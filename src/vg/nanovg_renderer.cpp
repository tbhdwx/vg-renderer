#include "nanovg_renderer.h"
#include "shape.h"
#include "../nanovg/nanovg.h"
#include <bx/allocator.h>
#include <bx/bx.h>
#include <bx/string.h>

namespace vg
{
NanoVGRenderer::NanoVGRenderer() : 
	m_Context(nullptr), 
	m_Gradients(nullptr),
	m_ImagePatterns(nullptr),
	m_NextGradientID(0),
	m_NextImagePatternID(0),
	m_NextFontID(0),
	m_Allocator(nullptr),
	m_FontData(nullptr)
{
}

NanoVGRenderer::~NanoVGRenderer()
{
	if (m_Context) {
		nvgDelete(m_Context);
		m_Context = nullptr;
	}
	
	for (uint32_t i = 0; i < VG_CONFIG_MAX_FONTS; ++i) {
		if (m_FontData[i]) {
			BX_FREE(m_Allocator, m_FontData[i]);
		}
	}
	BX_FREE(m_Allocator, m_FontData);

	BX_FREE(m_Allocator, m_Gradients);
	BX_FREE(m_Allocator, m_ImagePatterns);
}

bool NanoVGRenderer::init(bool edgeAA, uint8_t viewID, bx::AllocatorI* allocator)
{
	m_Allocator = allocator;

	m_Context = nvgCreate(edgeAA ? 1 : 0, viewID, allocator);
	if (!m_Context) {
		return false;
	}

	m_Gradients = (NVGpaint*)BX_ALLOC(allocator, sizeof(NVGpaint) * VG_CONFIG_MAX_GRADIENTS);
	m_ImagePatterns = (NVGpaint*)BX_ALLOC(allocator, sizeof(NVGpaint) * VG_CONFIG_MAX_IMAGE_PATTERNS);
	m_FontData = (void**)BX_ALLOC(allocator, sizeof(void*) * VG_CONFIG_MAX_FONTS);
	bx::memSet(m_FontData, 0, sizeof(void*) * VG_CONFIG_MAX_FONTS);

#if 1
	nvgMiterLimit(m_Context, 1e6f); // Large value to emulate BGFXVGRenderer's inability to convert miters to bevels.
#endif
	
	return true;
}

void NanoVGRenderer::BeginFrame(uint32_t windowWidth, uint32_t windowHeight, float devicePixelRatio)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	m_NextGradientID = 0;
	m_NextImagePatternID = 0;
	nvgBeginFrame(m_Context, (int)windowWidth, (int)windowHeight, devicePixelRatio);
}

void NanoVGRenderer::EndFrame()
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgEndFrame(m_Context);
}

void NanoVGRenderer::BeginPath()
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgBeginPath(m_Context);
}

void NanoVGRenderer::MoveTo(float x, float y)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgMoveTo(m_Context, x, y);
}

void NanoVGRenderer::LineTo(float x, float y)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgLineTo(m_Context, x, y);
}

void NanoVGRenderer::BezierTo(float c1x, float c1y, float c2x, float c2y, float x, float y)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgBezierTo(m_Context, c1x, c1y, c2x, c2y, x, y);
}

void NanoVGRenderer::ArcTo(float x1, float y1, float x2, float y2, float radius)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgArcTo(m_Context, x1, y1, x2, y2, radius);
}

void NanoVGRenderer::Rect(float x, float y, float w, float h)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgRect(m_Context, x, y, w, h);
}

void NanoVGRenderer::RoundedRect(float x, float y, float w, float h, float r)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgRoundedRect(m_Context, x, y, w, h, r);
}

void NanoVGRenderer::Circle(float cx, float cy, float radius)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgCircle(m_Context, cx, cy, radius);
}

void NanoVGRenderer::Polyline(const float* coords, uint32_t numPoints)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");

	for (uint32_t i = 0; i < numPoints; ++i) {
		nvgLineTo(m_Context, coords[0], coords[1]);
		coords += 2;
	}
}

void NanoVGRenderer::ClosePath()
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgClosePath(m_Context);
}

void NanoVGRenderer::FillConvexPath(uint32_t col, bool aa)
{
	BX_UNUSED(aa);
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");

	nvgFillColor(m_Context, nvgRGBA32(col));
	nvgFill(m_Context);
}

void NanoVGRenderer::FillConvexPath(GradientHandle handle, bool aa)
{
	BX_UNUSED(aa);
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	BX_CHECK(handle.idx < VG_CONFIG_MAX_GRADIENTS, "Invalid gradient handle");

	NVGpaint* paint = &m_Gradients[handle.idx];
	nvgFillPaint(m_Context, *paint);
	nvgFill(m_Context);
}

void NanoVGRenderer::FillConvexPath(ImagePatternHandle handle, bool aa)
{
	BX_UNUSED(aa);
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	BX_CHECK(handle.idx < VG_CONFIG_MAX_IMAGE_PATTERNS, "Invalid image pattern handle");

	NVGpaint* paint = &m_ImagePatterns[handle.idx];
	nvgFillPaint(m_Context, *paint);
	nvgFill(m_Context);
}

void NanoVGRenderer::FillConcavePath(Color col, bool aa)
{
	BX_UNUSED(aa);
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");

	nvgFillColor(m_Context, nvgRGBA32(col));
	nvgFill(m_Context);
}

void NanoVGRenderer::StrokePath(uint32_t col, float width, bool aa, LineCap::Enum lineCap, LineJoin::Enum lineJoin)
{
	BX_UNUSED(aa);
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");

	nvgLineJoin(m_Context, lineJoin == LineJoin::Miter ? NVG_MITER : (lineJoin == LineJoin::Round ? NVG_ROUND : NVG_BEVEL));
	nvgLineCap(m_Context, lineCap == LineCap::Butt ? NVG_BUTT : (lineCap == LineCap::Round ? NVG_ROUND : NVG_SQUARE));
	nvgStrokeColor(m_Context, nvgRGBA32(col));
	nvgStrokeWidth(m_Context, width);
	nvgStroke(m_Context);
}

void NanoVGRenderer::PushState()
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgSave(m_Context);
}

void NanoVGRenderer::PopState()
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgRestore(m_Context);
}

void NanoVGRenderer::ResetScissor()
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgResetScissor(m_Context);
}

void NanoVGRenderer::Scissor(float x, float y, float w, float h)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgScissor(m_Context, x, y, w, h);
}

bool NanoVGRenderer::IntersectScissor(float x, float y, float w, float h)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	return nvgIntersectScissor(m_Context, x, y, w, h);
}

void NanoVGRenderer::LoadIdentity()
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgResetTransform(m_Context);
}

void NanoVGRenderer::Scale(float x, float y)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgScale(m_Context, x, y);
}

void NanoVGRenderer::Translate(float x, float y)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgTranslate(m_Context, x, y);
}

void NanoVGRenderer::Rotate(float ang_rad)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgRotate(m_Context, ang_rad);
}

void NanoVGRenderer::ApplyTransform(const float* mtx, bool pre)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	if (pre) {
		nvgTransform(m_Context, mtx[0], mtx[1], mtx[2], mtx[3], mtx[4], mtx[5]);
	} else {
		float cur[6];
		nvgCurrentTransform(m_Context, cur);
		nvgResetTransform(m_Context);
		nvgTransform(m_Context, mtx[0], mtx[1], mtx[2], mtx[3], mtx[4], mtx[5]);
		nvgTransform(m_Context, cur[0], cur[1], cur[2], cur[3], cur[4], cur[5]);
	}
}

void NanoVGRenderer::SetGlobalAlpha(float alpha)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgGlobalAlpha(m_Context, alpha);
}

void NanoVGRenderer::Text(const Font& font, uint32_t alignment, Color color, float x, float y, const char* text, const char* end)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");

	nvgFontFaceId(m_Context, font.m_Handle.idx);
	nvgFontSize(m_Context, font.m_Size);
	nvgTextAlign(m_Context, alignment);
	nvgFillColor(m_Context, nvgRGBA32(color));
	nvgText(m_Context, x, y, text, end);
}

void NanoVGRenderer::TextBox(const Font& font, uint32_t alignment, Color color, float x, float y, float breakWidth, const char* text, const char* end)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");

	nvgFontFaceId(m_Context, font.m_Handle.idx);
	nvgFontSize(m_Context, font.m_Size);
	nvgTextAlign(m_Context, alignment);
	nvgFillColor(m_Context, nvgRGBA32(color));
	nvgTextBox(m_Context, x, y, breakWidth, text, end);
}

float NanoVGRenderer::CalcTextBounds(const Font& font, uint32_t alignment, float x, float y, const char* text, const char* end, float* bounds)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");

	nvgFontFaceId(m_Context, font.m_Handle.idx);
	nvgFontSize(m_Context, font.m_Size);
	nvgTextAlign(m_Context, alignment);
	return nvgTextBounds(m_Context, x, y, text, end, bounds);
}

void NanoVGRenderer::CalcTextBoxBounds(const Font& font, uint32_t alignment, float x, float y, float breakWidth, const char* text, const char* end, float* bounds, uint32_t flags)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");

	nvgFontFaceId(m_Context, font.m_Handle.idx);
	nvgFontSize(m_Context, font.m_Size);
	nvgTextAlign(m_Context, alignment);
	nvgTextBoxBounds(m_Context, x, y, breakWidth, text, end, bounds, flags);
}

float NanoVGRenderer::GetTextLineHeight(const Font& font, uint32_t alignment)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");

	float lh;
	nvgFontFaceId(m_Context, font.m_Handle.idx);
	nvgFontSize(m_Context, font.m_Size);
	nvgTextAlign(m_Context, alignment);
	nvgTextMetrics(m_Context, nullptr, nullptr, &lh);
	return lh;
}

int NanoVGRenderer::TextBreakLines(const Font& font, uint32_t alignment, const char* text, const char* end, float breakWidth, TextRow* rows, int numRows, uint32_t flags)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");

	nvgFontFaceId(m_Context, font.m_Handle.idx);
	nvgFontSize(m_Context, font.m_Size);
	nvgTextAlign(m_Context, alignment);
	return nvgTextBreakLines(m_Context, text, end, breakWidth, (NVGtextRow*)rows, numRows, flags);
}

int NanoVGRenderer::TextGlyphPositions(const Font& font, uint32_t alignment, float x, float y, const char* text, const char* end, GlyphPosition* glyphs, int maxGlyphs)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");

	nvgFontFaceId(m_Context, font.m_Handle.idx);
	nvgFontSize(m_Context, font.m_Size);
	nvgTextAlign(m_Context, alignment);
	return nvgTextGlyphPositions(m_Context, x, y, text, end, (NVGglyphPosition*)glyphs, maxGlyphs);
}

ImagePatternHandle NanoVGRenderer::ImagePattern(float cx, float cy, float w, float h, float angle, ImageHandle image, float alpha)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");

	uint32_t paintID = m_NextImagePatternID;
	NVGpaint* paint = &m_ImagePatterns[paintID];
	*paint = nvgImagePattern(m_Context, cx, cy, w, h, angle, (int)image.idx, alpha);

	m_NextImagePatternID = (m_NextImagePatternID + 1) % VG_CONFIG_MAX_IMAGE_PATTERNS;

	return { (uint16_t)paintID };
}

GradientHandle NanoVGRenderer::LinearGradient(float sx, float sy, float ex, float ey, vg::Color icol, vg::Color ocol)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");

	uint32_t paintID = m_NextGradientID;
	NVGpaint* paint = &m_Gradients[paintID];

	*paint = nvgLinearGradient(m_Context, sx, sy, ex, ey, nvgRGBA32(icol), nvgRGBA32(ocol));

	m_NextGradientID = (m_NextGradientID + 1) % VG_CONFIG_MAX_GRADIENTS;

	return { (uint16_t)paintID };
}

GradientHandle NanoVGRenderer::BoxGradient(float x, float y, float w, float h, float r, float f, vg::Color icol, vg::Color ocol)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");

	uint32_t paintID = m_NextGradientID;
	NVGpaint* paint = &m_Gradients[paintID];

	*paint = nvgBoxGradient(m_Context, x, y, w, h, r, f, nvgRGBA32(icol), nvgRGBA32(ocol));

	m_NextGradientID = (m_NextGradientID + 1) % VG_CONFIG_MAX_GRADIENTS;

	return { (uint16_t)paintID };
}

GradientHandle NanoVGRenderer::RadialGradient(float cx, float cy, float inr, float outr, vg::Color icol, vg::Color ocol)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");

	uint32_t paintID = m_NextGradientID;
	NVGpaint* paint = &m_Gradients[paintID];

	*paint = nvgRadialGradient(m_Context, cx, cy, inr, outr, nvgRGBA32(icol), nvgRGBA32(ocol));

	m_NextGradientID = (m_NextGradientID + 1) % VG_CONFIG_MAX_GRADIENTS;

	return { (uint16_t)paintID };
}

ImageHandle NanoVGRenderer::CreateImageRGBA(uint16_t w, uint16_t h, uint32_t imageFlags, const uint8_t* data)
{
	BX_UNUSED(imageFlags);
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");

	int imgID = nvgCreateImageRGBA(m_Context, (int)w, (int)h, 0, data);
	return { (uint16_t)imgID };
}

void NanoVGRenderer::UpdateImage(ImageHandle image, const uint8_t* data)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgUpdateImage(m_Context, image.idx, data);
}

void NanoVGRenderer::UpdateSubImage(ImageHandle image, uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint8_t* data)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	BX_UNUSED(x, y, w, h);
	nvgUpdateImage(m_Context, image.idx, data);
}

void NanoVGRenderer::GetImageSize(ImageHandle image, int* w, int* h)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgImageSize(m_Context, image.idx, w, h);
}

void NanoVGRenderer::DeleteImage(ImageHandle image)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");
	nvgDeleteImage(m_Context, image.idx);
}

bool NanoVGRenderer::IsImageHandleValid(ImageHandle image)
{
	return image.idx != 0;
}

FontHandle NanoVGRenderer::LoadFontFromMemory(const char* name, const uint8_t* data, uint32_t size)
{
	BX_CHECK(m_Context != nullptr, "NanoVG context is null!");

	if (m_NextFontID == VG_CONFIG_MAX_FONTS) {
		return VG_INVALID_HANDLE;
	}

	uint8_t* fontData = (uint8_t*)BX_ALLOC(m_Allocator, size);
	bx::memCopy(fontData, data, size);

	int fontHandle = nvgCreateFontMem(m_Context, name, fontData, size, 0);
	if (fontHandle == -1) {
		BX_FREE(m_Allocator, fontData);
		return VG_INVALID_HANDLE;
	}

	m_FontData[m_NextFontID++] = fontData;

	return{ (uint16_t)fontHandle };
}

Font NanoVGRenderer::CreateFontWithSize(const char* name, float size)
{
	Font f;
	f.m_Handle.idx = (uint16_t)nvgFindFont(m_Context, name);
	f.m_Size = size;
	return f;
}

Shape* NanoVGRenderer::CreateShape(uint32_t /*flags*/)
{
	bx::AllocatorI* allocator = m_Allocator;

	bx::MemoryBlock* memBlock = BX_NEW(allocator, bx::MemoryBlock)(allocator);
	Shape* shape = BX_NEW(allocator, Shape)(memBlock);
	shape->m_Flags = 0; // Caching isn't supported so ignore all flags.

	// TODO: Keep the shape ptr to make sure we aren't leaking any memory 
	// even if the owner of the shape forgets to destroy it.

	return shape;
}

void NanoVGRenderer::DestroyShape(Shape* shape)
{
	bx::AllocatorI* allocator = m_Allocator;

	BX_DELETE(allocator, (bx::MemoryBlock*)shape->m_CmdList);
	BX_DELETE(allocator, shape);
}

void NanoVGRenderer::SubmitShape(Shape* shape)
{
#define READ(type, buffer) *(type*)buffer; buffer += sizeof(type);

	const uint8_t* cmdList = (uint8_t*)shape->m_CmdList->more(0);
	const uint32_t cmdListSize = shape->m_CmdList->getSize();

	const uint8_t* cmdListEnd = cmdList + cmdListSize;

	const uint16_t firstGradientID = (uint16_t)m_NextGradientID;
	const uint16_t firstImagePatternID = (uint16_t)m_NextImagePatternID;
	BX_CHECK(firstGradientID + shape->m_NumGradients <= VG_CONFIG_MAX_GRADIENTS, "Not enough free gradients to render shape. Increase VG_MAX_GRADIENTS");
	BX_CHECK(firstImagePatternID + shape->m_NumImagePatterns <= VG_CONFIG_MAX_IMAGE_PATTERNS, "Not enough free image patterns to render shape. Increase VG_MAX_IMAGE_PATTERNS");

	while (cmdList < cmdListEnd) {
		ShapeCommand::Enum cmdType = *(ShapeCommand::Enum*)cmdList;
		cmdList += sizeof(ShapeCommand::Enum);

		switch (cmdType) {
		case ShapeCommand::BeginPath:
		{
			BeginPath();
			break;
		}
		case ShapeCommand::ClosePath:
		{
			ClosePath();
			break;
		}
		case ShapeCommand::MoveTo:
		{
			float* coords = (float*)cmdList;
			MoveTo(coords[0], coords[1]);
			cmdList += sizeof(float) * 2;
			break;
		}
		case ShapeCommand::LineTo:
		{
			float* coords = (float*)cmdList;
			LineTo(coords[0], coords[1]);
			cmdList += sizeof(float) * 2;
			break;
		}
		case ShapeCommand::BezierTo:
		{
			float* coords = (float*)cmdList;
			BezierTo(coords[0], coords[1], coords[2], coords[3], coords[4], coords[5]);
			cmdList += sizeof(float) * 6;
			break;
		}
		case ShapeCommand::ArcTo:
		{
			float* coords = (float*)cmdList;
			ArcTo(coords[0], coords[1], coords[2], coords[3], coords[4]);
			cmdList += sizeof(float) * 5;
			break;
		}
		case ShapeCommand::Rect:
		{
			float* coords = (float*)cmdList;
			Rect(coords[0], coords[1], coords[2], coords[3]);
			cmdList += sizeof(float) * 4;
			break;
		}
		case ShapeCommand::RoundedRect:
		{
			float* coords = (float*)cmdList;
			RoundedRect(coords[0], coords[1], coords[2], coords[3], coords[4]);
			cmdList += sizeof(float) * 5;
			break;
		}
		case ShapeCommand::Circle:
		{
			float* coords = (float*)cmdList;
			Circle(coords[0], coords[1], coords[2]);
			cmdList += sizeof(float) * 3;
			break;
		}
		case ShapeCommand::FillConvexColor:
		{
			Color col = READ(Color, cmdList);
			bool aa = READ(bool, cmdList);
			FillConvexPath(col, aa);
			break;
		}
		case ShapeCommand::FillConvexGradient:
		{
			GradientHandle handle = READ(GradientHandle, cmdList);
			bool aa = READ(bool, cmdList);

			handle.idx += firstGradientID;
			FillConvexPath(handle, aa);
			break;
		}
		case ShapeCommand::FillConvexImage:
		{
			ImagePatternHandle handle = READ(ImagePatternHandle, cmdList);
			bool aa = READ(bool, cmdList);

			handle.idx += firstImagePatternID;
			FillConvexPath(handle, aa);
			break;
		}
		case ShapeCommand::FillConcaveColor:
		{
			Color col = READ(Color, cmdList);
			bool aa = READ(bool, cmdList);
			FillConcavePath(col, aa);
			break;
		}
		case ShapeCommand::Stroke:
		{
			Color col = READ(Color, cmdList);
			float width = READ(float, cmdList);
			bool aa = READ(bool, cmdList);
			LineCap::Enum lineCap = READ(LineCap::Enum, cmdList);
			LineJoin::Enum lineJoin = READ(LineJoin::Enum, cmdList);
			StrokePath(col, width, aa, lineCap, lineJoin);
			break;
		}
		case ShapeCommand::LinearGradient:
		{
			float sx = READ(float, cmdList);
			float sy = READ(float, cmdList);
			float ex = READ(float, cmdList);
			float ey = READ(float, cmdList);
			Color icol = READ(Color, cmdList);
			Color ocol = READ(Color, cmdList);
			LinearGradient(sx, sy, ex, ey, icol, ocol);
			break;
		}
		case ShapeCommand::BoxGradient:
		{
			float x = READ(float, cmdList);
			float y = READ(float, cmdList);
			float w = READ(float, cmdList);
			float h = READ(float, cmdList);
			float r = READ(float, cmdList);
			float f = READ(float, cmdList);
			Color icol = READ(Color, cmdList);
			Color ocol = READ(Color, cmdList);
			BoxGradient(x, y, w, h, r, f, icol, ocol);
			break;
		}
		case ShapeCommand::RadialGradient:
		{
			float cx = READ(float, cmdList);
			float cy = READ(float, cmdList);
			float inr = READ(float, cmdList);
			float outr = READ(float, cmdList);
			Color icol = READ(Color, cmdList);
			Color ocol = READ(Color, cmdList);
			RadialGradient(cx, cy, inr, outr, icol, ocol);
			break;
		}
		case ShapeCommand::ImagePattern:
		{
			float cx = READ(float, cmdList);
			float cy = READ(float, cmdList);
			float w = READ(float, cmdList);
			float h = READ(float, cmdList);
			float angle = READ(float, cmdList);
			ImageHandle image = READ(ImageHandle, cmdList);
			float alpha = READ(float, cmdList);
			ImagePattern(cx, cy, w, h, angle, image, alpha);
			break;
		}
		case ShapeCommand::TextStatic:
		{
			Font font = READ(Font, cmdList);
			uint32_t alignment = READ(uint32_t, cmdList);
			Color col = READ(Color, cmdList);
			float x = READ(float, cmdList);
			float y = READ(float, cmdList);
			uint32_t len = READ(uint32_t, cmdList);
			const char* text = (const char*)cmdList;
			cmdList += len;
			Text(font, alignment, col, x, y, text, text + len);
			break;
		}
#if VG_CONFIG_SHAPE_DYNAMIC_TEXT
		case ShapeCommand::TextDynamic:
		{
			BX_CHECK(false, "Do not call this version of SubmitShape if you are using Text templates.");

			// Skip the command
			cmdList += sizeof(Font) + sizeof(uint32_t) * 2 + sizeof(Color) + sizeof(float) * 2;
			break;
		}
#endif
		}
	}

	// Free shape gradients and image patterns
	m_NextGradientID = firstGradientID;
	m_NextImagePatternID = firstImagePatternID;

#undef READ
}

#if VG_CONFIG_SHAPE_DYNAMIC_TEXT
// TODO: Find a way to merge those 2 functions. They are exactly the same except from the way TextDynamic commands are processed.
// Ideally both of them should call a generic version which does all the work (pointer to std::function?)
void NanoVGRenderer::SubmitShape(Shape* shape, GetStringByIDFunc stringCallback, void* userData)
{
#define READ(type, buffer) *(type*)buffer; buffer += sizeof(type);

	const uint8_t* cmdList = (uint8_t*)shape->m_CmdList->more(0);
	const uint32_t cmdListSize = shape->m_CmdList->getSize();

	const uint8_t* cmdListEnd = cmdList + cmdListSize;

	const uint16_t firstGradientID = (uint16_t)m_NextGradientID;
	const uint16_t firstImagePatternID = (uint16_t)m_NextImagePatternID;
	BX_CHECK(firstGradientID + shape->m_NumGradients <= VG_CONFIG_MAX_GRADIENTS, "Not enough free gradients to render shape. Increase VG_MAX_GRADIENTS");
	BX_CHECK(firstImagePatternID + shape->m_NumImagePatterns <= VG_CONFIG_MAX_IMAGE_PATTERNS, "Not enough free image patterns to render shape. Increase VG_MAX_IMAGE_PATTERNS");

	while (cmdList < cmdListEnd) {
		ShapeCommand::Enum cmdType = *(ShapeCommand::Enum*)cmdList;
		cmdList += sizeof(ShapeCommand::Enum);

		switch (cmdType) {
		case ShapeCommand::BeginPath:
		{
			BeginPath();
			break;
		}
		case ShapeCommand::ClosePath:
		{
			ClosePath();
			break;
		}
		case ShapeCommand::MoveTo:
		{
			float* coords = (float*)cmdList;
			MoveTo(coords[0], coords[1]);
			cmdList += sizeof(float) * 2;
			break;
		}
		case ShapeCommand::LineTo:
		{
			float* coords = (float*)cmdList;
			LineTo(coords[0], coords[1]);
			cmdList += sizeof(float) * 2;
			break;
		}
		case ShapeCommand::BezierTo:
		{
			float* coords = (float*)cmdList;
			BezierTo(coords[0], coords[1], coords[2], coords[3], coords[4], coords[5]);
			cmdList += sizeof(float) * 6;
			break;
		}
		case ShapeCommand::ArcTo:
		{
			float* coords = (float*)cmdList;
			ArcTo(coords[0], coords[1], coords[2], coords[3], coords[4]);
			cmdList += sizeof(float) * 5;
			break;
		}
		case ShapeCommand::Rect:
		{
			float* coords = (float*)cmdList;
			Rect(coords[0], coords[1], coords[2], coords[3]);
			cmdList += sizeof(float) * 4;
			break;
		}
		case ShapeCommand::RoundedRect:
		{
			float* coords = (float*)cmdList;
			RoundedRect(coords[0], coords[1], coords[2], coords[3], coords[4]);
			cmdList += sizeof(float) * 5;
			break;
		}
		case ShapeCommand::Circle:
		{
			float* coords = (float*)cmdList;
			Circle(coords[0], coords[1], coords[2]);
			cmdList += sizeof(float) * 3;
			break;
		}
		case ShapeCommand::FillConvexColor:
		{
			Color col = READ(Color, cmdList);
			bool aa = READ(bool, cmdList);
			FillConvexPath(col, aa);
			break;
		}
		case ShapeCommand::FillConvexGradient:
		{
			GradientHandle handle = READ(GradientHandle, cmdList);
			bool aa = READ(bool, cmdList);

			handle.idx += firstGradientID;
			FillConvexPath(handle, aa);
			break;
		}
		case ShapeCommand::FillConvexImage:
		{
			ImagePatternHandle handle = READ(ImagePatternHandle, cmdList);
			bool aa = READ(bool, cmdList);

			handle.idx += firstImagePatternID;
			FillConvexPath(handle, aa);
			break;
		}
		case ShapeCommand::FillConcaveColor:
		{
			Color col = READ(Color, cmdList);
			bool aa = READ(bool, cmdList);
			FillConcavePath(col, aa);
			break;
		}
		case ShapeCommand::Stroke:
		{
			Color col = READ(Color, cmdList);
			float width = READ(float, cmdList);
			bool aa = READ(bool, cmdList);
			LineCap::Enum lineCap = READ(LineCap::Enum, cmdList);
			LineJoin::Enum lineJoin = READ(LineJoin::Enum, cmdList);
			StrokePath(col, width, aa, lineCap, lineJoin);
			break;
		}
		case ShapeCommand::LinearGradient:
		{
			float sx = READ(float, cmdList);
			float sy = READ(float, cmdList);
			float ex = READ(float, cmdList);
			float ey = READ(float, cmdList);
			Color icol = READ(Color, cmdList);
			Color ocol = READ(Color, cmdList);
			LinearGradient(sx, sy, ex, ey, icol, ocol);
			break;
		}
		case ShapeCommand::BoxGradient:
		{
			float x = READ(float, cmdList);
			float y = READ(float, cmdList);
			float w = READ(float, cmdList);
			float h = READ(float, cmdList);
			float r = READ(float, cmdList);
			float f = READ(float, cmdList);
			Color icol = READ(Color, cmdList);
			Color ocol = READ(Color, cmdList);
			BoxGradient(x, y, w, h, r, f, icol, ocol);
			break;
		}
		case ShapeCommand::RadialGradient:
		{
			float cx = READ(float, cmdList);
			float cy = READ(float, cmdList);
			float inr = READ(float, cmdList);
			float outr = READ(float, cmdList);
			Color icol = READ(Color, cmdList);
			Color ocol = READ(Color, cmdList);
			RadialGradient(cx, cy, inr, outr, icol, ocol);
			break;
		}
		case ShapeCommand::ImagePattern:
		{
			float cx = READ(float, cmdList);
			float cy = READ(float, cmdList);
			float w = READ(float, cmdList);
			float h = READ(float, cmdList);
			float angle = READ(float, cmdList);
			ImageHandle image = READ(ImageHandle, cmdList);
			float alpha = READ(float, cmdList);
			ImagePattern(cx, cy, w, h, angle, image, alpha);
			break;
		}
		case ShapeCommand::TextStatic:
		{
			Font font = READ(Font, cmdList);
			uint32_t alignment = READ(uint32_t, cmdList);
			Color col = READ(Color, cmdList);
			float x = READ(float, cmdList);
			float y = READ(float, cmdList);
			uint32_t len = READ(uint32_t, cmdList);
			const char* text = (const char*)cmdList;
			cmdList += len;
			Text(font, alignment, col, x, y, text, text + len);
			break;
		}
		case ShapeCommand::TextDynamic:
		{
			Font font = READ(Font, cmdList);
			uint32_t alignment = READ(uint32_t, cmdList);
			Color col = READ(Color, cmdList);
			float x = READ(float, cmdList);
			float y = READ(float, cmdList);
			uint32_t stringID = READ(uint32_t, cmdList);

			uint32_t len;
			const char* text = stringCallback(stringID, len, userData);
			const char* end = len != ~0u ? text + len : text + bx::strLen(text);

			Text(font, alignment, col, x, y, text, end);
			break;
		}
		}
	}

	// Free shape gradients and image patterns
	m_NextGradientID = firstGradientID;
	m_NextImagePatternID = firstImagePatternID;

#undef READ
}
#endif
}
