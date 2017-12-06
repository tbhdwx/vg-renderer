static const uint8_t vs_gradient_glsl[311] =
{
	0x56, 0x53, 0x48, 0x05, 0x70, 0x94, 0x72, 0xf8, 0x01, 0x00, 0x0f, 0x75, 0x5f, 0x6d, 0x6f, 0x64, // VSH.p.r....u_mod
	0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x04, 0x01, 0x00, 0x00, 0x01, 0x00, // elViewProj......
	0x12, 0x01, 0x00, 0x00, 0x61, 0x74, 0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x20, 0x68, 0x69, // ....attribute hi
	0x67, 0x68, 0x70, 0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, // ghp vec2 a_posit
	0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x68, 0x69, 0x67, // ion;.varying hig
	0x68, 0x70, 0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x76, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, // hp vec2 v_positi
	0x6f, 0x6e, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x68, 0x69, 0x67, 0x68, // on;.uniform high
	0x70, 0x20, 0x6d, 0x61, 0x74, 0x34, 0x20, 0x75, 0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, // p mat4 u_modelVi
	0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x3b, 0x0a, 0x76, 0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, // ewProj;.void mai
	0x6e, 0x20, 0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x68, 0x69, 0x67, 0x68, 0x70, 0x20, 0x76, // n ().{.  highp v
	0x65, 0x63, 0x34, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x20, 0x20, // ec4 tmpvar_1;.  
	0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, 0x7a, 0x77, 0x20, 0x3d, 0x20, 0x76, 0x65, // tmpvar_1.zw = ve
	0x63, 0x32, 0x28, 0x30, 0x2e, 0x30, 0x2c, 0x20, 0x31, 0x2e, 0x30, 0x29, 0x3b, 0x0a, 0x20, 0x20, // c2(0.0, 1.0);.  
	0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, 0x78, 0x79, 0x20, 0x3d, 0x20, 0x61, 0x5f, // tmpvar_1.xy = a_
	0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x20, 0x20, 0x67, 0x6c, 0x5f, 0x50, // position;.  gl_P
	0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x3d, 0x20, 0x28, 0x75, 0x5f, 0x6d, 0x6f, 0x64, // osition = (u_mod
	0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x20, 0x2a, 0x20, 0x74, 0x6d, 0x70, // elViewProj * tmp
	0x76, 0x61, 0x72, 0x5f, 0x31, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x76, 0x5f, 0x70, 0x6f, 0x73, 0x69, // var_1);.  v_posi
	0x74, 0x69, 0x6f, 0x6e, 0x20, 0x3d, 0x20, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, // tion = a_positio
	0x6e, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00,                                                       // n;.}...
};
static const uint8_t vs_gradient_spv[2569] =
{
	0x56, 0x53, 0x48, 0x05, 0x70, 0x94, 0x72, 0xf8, 0x01, 0x00, 0x0f, 0x75, 0x5f, 0x6d, 0x6f, 0x64, // VSH.p.r....u_mod
	0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x04, 0x01, 0x00, 0x00, 0x01, 0x00, // elViewProj......
	0xe4, 0x09, 0x00, 0x00, 0x03, 0x02, 0x23, 0x07, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x08, 0x00, // ......#.........
	0x54, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, // Ta..............
	0x0b, 0x00, 0x06, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x4c, 0x53, 0x4c, 0x2e, 0x73, 0x74, 0x64, // ........GLSL.std
	0x2e, 0x34, 0x35, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, // .450............
	0x01, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x16, 0x00, 0x00, // ................
	0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0xa6, 0x14, 0x00, 0x00, 0xd8, 0x0c, 0x00, 0x00, // main............
	0xcd, 0x0f, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x05, 0x00, 0x00, 0x00, 0xf4, 0x01, 0x00, 0x00, // ................
	0x05, 0x00, 0x04, 0x00, 0x1f, 0x16, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, // ........main....
	0x05, 0x00, 0x04, 0x00, 0x1a, 0x04, 0x00, 0x00, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x00, 0x00, // ........Output..
	0x06, 0x00, 0x06, 0x00, 0x1a, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0x6c, 0x5f, 0x50, // ............gl_P
	0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x00, 0x06, 0x00, 0x06, 0x00, 0x1a, 0x04, 0x00, 0x00, // osition.........
	0x01, 0x00, 0x00, 0x00, 0x76, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x00, 0x00, // ....v_position..
	0x05, 0x00, 0x05, 0x00, 0x2e, 0x13, 0x00, 0x00, 0x40, 0x6d, 0x61, 0x69, 0x6e, 0x28, 0x76, 0x66, // ........@main(vf
	0x32, 0x3b, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0xa6, 0x1b, 0x00, 0x00, 0x61, 0x5f, 0x70, 0x6f, // 2;..........a_po
	0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0x0f, 0x12, 0x00, 0x00, // sition..........
	0x5f, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x5f, 0x00, 0x00, 0x00, 0x05, 0x00, 0x04, 0x00, // _varying_.......
	0x76, 0x03, 0x00, 0x00, 0x24, 0x47, 0x6c, 0x6f, 0x62, 0x61, 0x6c, 0x00, 0x06, 0x00, 0x06, 0x00, // v...$Global.....
	0x76, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x52, 0x65, // v.......u_viewRe
	0x63, 0x74, 0x00, 0x00, 0x06, 0x00, 0x06, 0x00, 0x76, 0x03, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, // ct......v.......
	0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x54, 0x65, 0x78, 0x65, 0x6c, 0x00, 0x06, 0x00, 0x05, 0x00, // u_viewTexel.....
	0x76, 0x03, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x00, 0x00, // v.......u_view..
	0x06, 0x00, 0x06, 0x00, 0x76, 0x03, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x75, 0x5f, 0x69, 0x6e, // ....v.......u_in
	0x76, 0x56, 0x69, 0x65, 0x77, 0x00, 0x00, 0x00, 0x06, 0x00, 0x05, 0x00, 0x76, 0x03, 0x00, 0x00, // vView.......v...
	0x04, 0x00, 0x00, 0x00, 0x75, 0x5f, 0x70, 0x72, 0x6f, 0x6a, 0x00, 0x00, 0x06, 0x00, 0x06, 0x00, // ....u_proj......
	0x76, 0x03, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x75, 0x5f, 0x69, 0x6e, 0x76, 0x50, 0x72, 0x6f, // v.......u_invPro
	0x6a, 0x00, 0x00, 0x00, 0x06, 0x00, 0x06, 0x00, 0x76, 0x03, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, // j.......v.......
	0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x00, 0x00, 0x06, 0x00, 0x07, 0x00, // u_viewProj......
	0x76, 0x03, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x75, 0x5f, 0x69, 0x6e, 0x76, 0x56, 0x69, 0x65, // v.......u_invVie
	0x77, 0x50, 0x72, 0x6f, 0x6a, 0x00, 0x00, 0x00, 0x06, 0x00, 0x05, 0x00, 0x76, 0x03, 0x00, 0x00, // wProj.......v...
	0x08, 0x00, 0x00, 0x00, 0x75, 0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x00, 0x06, 0x00, 0x06, 0x00, // ....u_model.....
	0x76, 0x03, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x75, 0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, // v.......u_modelV
	0x69, 0x65, 0x77, 0x00, 0x06, 0x00, 0x07, 0x00, 0x76, 0x03, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, // iew.....v.......
	0x75, 0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x00, // u_modelViewProj.
	0x06, 0x00, 0x06, 0x00, 0x76, 0x03, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x75, 0x5f, 0x61, 0x6c, // ....v.......u_al
	0x70, 0x68, 0x61, 0x52, 0x65, 0x66, 0x34, 0x00, 0x05, 0x00, 0x03, 0x00, 0x42, 0x13, 0x00, 0x00, // phaRef4.....B...
	0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0xbf, 0x40, 0x00, 0x00, 0x61, 0x5f, 0x70, 0x6f, // .........@..a_po
	0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0xa6, 0x14, 0x00, 0x00, // sition..........
	0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, // a_position......
	0x08, 0x10, 0x00, 0x00, 0x66, 0x6c, 0x61, 0x74, 0x74, 0x65, 0x6e, 0x54, 0x65, 0x6d, 0x70, 0x00, // ....flattenTemp.
	0x05, 0x00, 0x04, 0x00, 0x9a, 0x16, 0x00, 0x00, 0x70, 0x61, 0x72, 0x61, 0x6d, 0x00, 0x00, 0x00, // ........param...
	0x05, 0x00, 0x0a, 0x00, 0xd8, 0x0c, 0x00, 0x00, 0x40, 0x65, 0x6e, 0x74, 0x72, 0x79, 0x50, 0x6f, // ........@entryPo
	0x69, 0x6e, 0x74, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x5f, 0x67, 0x6c, 0x5f, 0x50, 0x6f, 0x73, // intOutput_gl_Pos
	0x69, 0x74, 0x69, 0x6f, 0x6e, 0x00, 0x00, 0x00, 0x05, 0x00, 0x04, 0x00, 0xe5, 0x03, 0x00, 0x00, // ition...........
	0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x00, 0x00, 0x06, 0x00, 0x06, 0x00, 0xe5, 0x03, 0x00, 0x00, // Output..........
	0x00, 0x00, 0x00, 0x00, 0x76, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x00, 0x00, // ....v_position..
	0x05, 0x00, 0x07, 0x00, 0xcd, 0x0f, 0x00, 0x00, 0x40, 0x65, 0x6e, 0x74, 0x72, 0x79, 0x50, 0x6f, // ........@entryPo
	0x69, 0x6e, 0x74, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, // intOutput...G...
	0x20, 0x01, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, //  .......@...H...
	0x76, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // v.......#.......
	0x48, 0x00, 0x05, 0x00, 0x76, 0x03, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, // H...v.......#...
	0x10, 0x00, 0x00, 0x00, 0x48, 0x00, 0x04, 0x00, 0x76, 0x03, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, // ....H...v.......
	0x04, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x76, 0x03, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, // ....H...v.......
	0x23, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x76, 0x03, 0x00, 0x00, // #... ...H...v...
	0x02, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x48, 0x00, 0x04, 0x00, // ............H...
	0x76, 0x03, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, // v...........H...
	0x76, 0x03, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, // v.......#...`...
	0x48, 0x00, 0x05, 0x00, 0x76, 0x03, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, // H...v...........
	0x10, 0x00, 0x00, 0x00, 0x48, 0x00, 0x04, 0x00, 0x76, 0x03, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, // ....H...v.......
	0x04, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x76, 0x03, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, // ....H...v.......
	0x23, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x76, 0x03, 0x00, 0x00, // #.......H...v...
	0x04, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x48, 0x00, 0x04, 0x00, // ............H...
	0x76, 0x03, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, // v...........H...
	0x76, 0x03, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, // v.......#.......
	0x48, 0x00, 0x05, 0x00, 0x76, 0x03, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, // H...v...........
	0x10, 0x00, 0x00, 0x00, 0x48, 0x00, 0x04, 0x00, 0x76, 0x03, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, // ....H...v.......
	0x04, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x76, 0x03, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, // ....H...v.......
	0x23, 0x00, 0x00, 0x00, 0x20, 0x01, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x76, 0x03, 0x00, 0x00, // #... ...H...v...
	0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x48, 0x00, 0x04, 0x00, // ............H...
	0x76, 0x03, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, // v...........H...
	0x76, 0x03, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x60, 0x01, 0x00, 0x00, // v.......#...`...
	0x48, 0x00, 0x05, 0x00, 0x76, 0x03, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, // H...v...........
	0x10, 0x00, 0x00, 0x00, 0x48, 0x00, 0x04, 0x00, 0x76, 0x03, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, // ....H...v.......
	0x04, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x76, 0x03, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, // ....H...v.......
	0x23, 0x00, 0x00, 0x00, 0xa0, 0x01, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x76, 0x03, 0x00, 0x00, // #.......H...v...
	0x08, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x48, 0x00, 0x04, 0x00, // ............H...
	0x76, 0x03, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, // v...........H...
	0x76, 0x03, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0xa0, 0x09, 0x00, 0x00, // v.......#.......
	0x48, 0x00, 0x05, 0x00, 0x76, 0x03, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, // H...v...........
	0x10, 0x00, 0x00, 0x00, 0x48, 0x00, 0x04, 0x00, 0x76, 0x03, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, // ....H...v.......
	0x04, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x76, 0x03, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, // ....H...v.......
	0x23, 0x00, 0x00, 0x00, 0xe0, 0x09, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x76, 0x03, 0x00, 0x00, // #.......H...v...
	0x0a, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, // ............H...
	0x76, 0x03, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x20, 0x0a, 0x00, 0x00, // v.......#... ...
	0x47, 0x00, 0x03, 0x00, 0x76, 0x03, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, // G...v.......G...
	0x42, 0x13, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, // B...".......G...
	0xa6, 0x14, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, // ............G...
	0xd8, 0x0c, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, // ............G...
	0xcd, 0x0f, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x00, 0x02, 0x00, // ................
	0x08, 0x00, 0x00, 0x00, 0x21, 0x00, 0x03, 0x00, 0x02, 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, // ....!...........
	0x16, 0x00, 0x03, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00, // ........ .......
	0x13, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, // ............ ...
	0x90, 0x02, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00, // ................
	0x1d, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x04, 0x00, // ................
	0x1a, 0x04, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x21, 0x00, 0x04, 0x00, // ............!...
	0xfb, 0x08, 0x00, 0x00, 0x1a, 0x04, 0x00, 0x00, 0x90, 0x02, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, // ............ ...
	0x97, 0x06, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x1a, 0x04, 0x00, 0x00, 0x15, 0x00, 0x04, 0x00, // ................
	0x0c, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, // .... .......+...
	0x0c, 0x00, 0x00, 0x00, 0x0e, 0x0a, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, // ............+...
	0x0d, 0x00, 0x00, 0x00, 0x0c, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x05, 0x00, // ............,...
	0x13, 0x00, 0x00, 0x00, 0x1f, 0x07, 0x00, 0x00, 0x0c, 0x0a, 0x00, 0x00, 0x0c, 0x0a, 0x00, 0x00, // ................
	0x2b, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x0b, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // +...............
	0x2b, 0x00, 0x04, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x8a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, // +..............?
	0x18, 0x00, 0x04, 0x00, 0x65, 0x00, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, // ....e...........
	0x15, 0x00, 0x04, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........ .......
	0x2b, 0x00, 0x04, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x6a, 0x0a, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, // +.......j... ...
	0x1c, 0x00, 0x04, 0x00, 0x20, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x6a, 0x0a, 0x00, 0x00, // .... ...e...j...
	0x1e, 0x00, 0x0e, 0x00, 0x76, 0x03, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00, // ....v...........
	0x65, 0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, // e...e...e...e...
	0x65, 0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x20, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, // e...e... ...e...
	0x65, 0x00, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0xf3, 0x05, 0x00, 0x00, // e....... .......
	0x02, 0x00, 0x00, 0x00, 0x76, 0x03, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0xf3, 0x05, 0x00, 0x00, // ....v...;.......
	0x42, 0x13, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00, // B.......+.......
	0x29, 0x0a, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0xe2, 0x02, 0x00, 0x00, // )....... .......
	0x02, 0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x9a, 0x02, 0x00, 0x00, // ....e... .......
	0x07, 0x00, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x91, 0x02, 0x00, 0x00, // ........ .......
	0x01, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x91, 0x02, 0x00, 0x00, // ........;.......
	0xa6, 0x14, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x9b, 0x02, 0x00, 0x00, // ........ .......
	0x03, 0x00, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x9b, 0x02, 0x00, 0x00, // ........;.......
	0xd8, 0x0c, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x03, 0x00, 0xe5, 0x03, 0x00, 0x00, // ................
	0x13, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x62, 0x06, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, // .... ...b.......
	0xe5, 0x03, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x62, 0x06, 0x00, 0x00, 0xcd, 0x0f, 0x00, 0x00, // ....;...b.......
	0x03, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x92, 0x02, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, // .... ...........
	0x13, 0x00, 0x00, 0x00, 0x36, 0x00, 0x05, 0x00, 0x08, 0x00, 0x00, 0x00, 0x1f, 0x16, 0x00, 0x00, // ....6...........
	0x00, 0x00, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0xf8, 0x00, 0x02, 0x00, 0x53, 0x61, 0x00, 0x00, // ............Sa..
	0x3b, 0x00, 0x04, 0x00, 0x97, 0x06, 0x00, 0x00, 0x08, 0x10, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, // ;...............
	0x3b, 0x00, 0x04, 0x00, 0x90, 0x02, 0x00, 0x00, 0x9a, 0x16, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, // ;...............
	0x3d, 0x00, 0x04, 0x00, 0x13, 0x00, 0x00, 0x00, 0xbf, 0x40, 0x00, 0x00, 0xa6, 0x14, 0x00, 0x00, // =........@......
	0x3e, 0x00, 0x03, 0x00, 0x9a, 0x16, 0x00, 0x00, 0xbf, 0x40, 0x00, 0x00, 0x39, 0x00, 0x05, 0x00, // >........@..9...
	0x1a, 0x04, 0x00, 0x00, 0x05, 0x61, 0x00, 0x00, 0x2e, 0x13, 0x00, 0x00, 0x9a, 0x16, 0x00, 0x00, // .....a..........
	0x3e, 0x00, 0x03, 0x00, 0x08, 0x10, 0x00, 0x00, 0x05, 0x61, 0x00, 0x00, 0x41, 0x00, 0x05, 0x00, // >........a..A...
	0x9a, 0x02, 0x00, 0x00, 0x54, 0x34, 0x00, 0x00, 0x08, 0x10, 0x00, 0x00, 0x0b, 0x0a, 0x00, 0x00, // ....T4..........
	0x3d, 0x00, 0x04, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x54, 0x34, 0x00, 0x00, // =...........T4..
	0x3e, 0x00, 0x03, 0x00, 0xd8, 0x0c, 0x00, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x41, 0x00, 0x05, 0x00, // >...........A...
	0x90, 0x02, 0x00, 0x00, 0x27, 0x41, 0x00, 0x00, 0x08, 0x10, 0x00, 0x00, 0x0e, 0x0a, 0x00, 0x00, // ....'A..........
	0x3d, 0x00, 0x04, 0x00, 0x13, 0x00, 0x00, 0x00, 0xdf, 0x1c, 0x00, 0x00, 0x27, 0x41, 0x00, 0x00, // =...........'A..
	0x41, 0x00, 0x05, 0x00, 0x92, 0x02, 0x00, 0x00, 0x01, 0x5c, 0x00, 0x00, 0xcd, 0x0f, 0x00, 0x00, // A...............
	0x0b, 0x0a, 0x00, 0x00, 0x3e, 0x00, 0x03, 0x00, 0x01, 0x5c, 0x00, 0x00, 0xdf, 0x1c, 0x00, 0x00, // ....>...........
	0xfd, 0x00, 0x01, 0x00, 0x38, 0x00, 0x01, 0x00, 0x36, 0x00, 0x05, 0x00, 0x1a, 0x04, 0x00, 0x00, // ....8...6.......
	0x2e, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfb, 0x08, 0x00, 0x00, 0x37, 0x00, 0x03, 0x00, // ............7...
	0x90, 0x02, 0x00, 0x00, 0xa6, 0x1b, 0x00, 0x00, 0xf8, 0x00, 0x02, 0x00, 0x23, 0x59, 0x00, 0x00, // ............#Y..
	0x3b, 0x00, 0x04, 0x00, 0x97, 0x06, 0x00, 0x00, 0x0f, 0x12, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, // ;...............
	0x41, 0x00, 0x05, 0x00, 0x90, 0x02, 0x00, 0x00, 0xf9, 0x2b, 0x00, 0x00, 0x0f, 0x12, 0x00, 0x00, // A........+......
	0x0e, 0x0a, 0x00, 0x00, 0x3e, 0x00, 0x03, 0x00, 0xf9, 0x2b, 0x00, 0x00, 0x1f, 0x07, 0x00, 0x00, // ....>....+......
	0x3d, 0x00, 0x04, 0x00, 0x13, 0x00, 0x00, 0x00, 0x16, 0x61, 0x00, 0x00, 0xa6, 0x1b, 0x00, 0x00, // =........a......
	0x51, 0x00, 0x05, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x09, 0x39, 0x00, 0x00, 0x16, 0x61, 0x00, 0x00, // Q........9...a..
	0x00, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00, 0x0d, 0x00, 0x00, 0x00, 0xb5, 0x5e, 0x00, 0x00, // ....Q........^..
	0x16, 0x61, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x50, 0x00, 0x07, 0x00, 0x1d, 0x00, 0x00, 0x00, // .a......P.......
	0x65, 0x31, 0x00, 0x00, 0x09, 0x39, 0x00, 0x00, 0xb5, 0x5e, 0x00, 0x00, 0x0c, 0x0a, 0x00, 0x00, // e1...9...^......
	0x8a, 0x00, 0x00, 0x00, 0x41, 0x00, 0x05, 0x00, 0xe2, 0x02, 0x00, 0x00, 0x0a, 0x2b, 0x00, 0x00, // ....A........+..
	0x42, 0x13, 0x00, 0x00, 0x29, 0x0a, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x65, 0x00, 0x00, 0x00, // B...)...=...e...
	0xd4, 0x3b, 0x00, 0x00, 0x0a, 0x2b, 0x00, 0x00, 0x90, 0x00, 0x05, 0x00, 0x1d, 0x00, 0x00, 0x00, // .;...+..........
	0x80, 0x3a, 0x00, 0x00, 0x65, 0x31, 0x00, 0x00, 0xd4, 0x3b, 0x00, 0x00, 0x41, 0x00, 0x05, 0x00, // .:..e1...;..A...
	0x9a, 0x02, 0x00, 0x00, 0x40, 0x37, 0x00, 0x00, 0x0f, 0x12, 0x00, 0x00, 0x0b, 0x0a, 0x00, 0x00, // ....@7..........
	0x3e, 0x00, 0x03, 0x00, 0x40, 0x37, 0x00, 0x00, 0x80, 0x3a, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, // >...@7...:..=...
	0x13, 0x00, 0x00, 0x00, 0xfe, 0x1f, 0x00, 0x00, 0xa6, 0x1b, 0x00, 0x00, 0x41, 0x00, 0x05, 0x00, // ............A...
	0x90, 0x02, 0x00, 0x00, 0x0e, 0x3b, 0x00, 0x00, 0x0f, 0x12, 0x00, 0x00, 0x0e, 0x0a, 0x00, 0x00, // .....;..........
	0x3e, 0x00, 0x03, 0x00, 0x0e, 0x3b, 0x00, 0x00, 0xfe, 0x1f, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, // >....;......=...
	0x1a, 0x04, 0x00, 0x00, 0xba, 0x3a, 0x00, 0x00, 0x0f, 0x12, 0x00, 0x00, 0xfe, 0x00, 0x02, 0x00, // .....:..........
	0xba, 0x3a, 0x00, 0x00, 0x38, 0x00, 0x01, 0x00, 0x00,                                           // .:..8....
};
static const uint8_t vs_gradient_dx9[289] =
{
	0x56, 0x53, 0x48, 0x05, 0x70, 0x94, 0x72, 0xf8, 0x01, 0x00, 0x0f, 0x75, 0x5f, 0x6d, 0x6f, 0x64, // VSH.p.r....u_mod
	0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x04, 0x01, 0x00, 0x00, 0x04, 0x00, // elViewProj......
	0xfc, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfe, 0xff, 0xfe, 0xff, 0x23, 0x00, 0x43, 0x54, 0x41, 0x42, // ..........#.CTAB
	0x1c, 0x00, 0x00, 0x00, 0x57, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfe, 0xff, 0x01, 0x00, 0x00, 0x00, // ....W...........
	0x1c, 0x00, 0x00, 0x00, 0x00, 0x91, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, // ........P...0...
	0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........@.......
	0x75, 0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x00, // u_modelViewProj.
	0x03, 0x00, 0x03, 0x00, 0x04, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x76, 0x73, 0x5f, 0x33, 0x5f, 0x30, 0x00, 0x4d, 0x69, 0x63, 0x72, 0x6f, 0x73, 0x6f, 0x66, 0x74, // vs_3_0.Microsoft
	0x20, 0x28, 0x52, 0x29, 0x20, 0x48, 0x4c, 0x53, 0x4c, 0x20, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, //  (R) HLSL Shader
	0x20, 0x43, 0x6f, 0x6d, 0x70, 0x69, 0x6c, 0x65, 0x72, 0x20, 0x39, 0x2e, 0x32, 0x39, 0x2e, 0x39, //  Compiler 9.29.9
	0x35, 0x32, 0x2e, 0x33, 0x31, 0x31, 0x31, 0x00, 0x1f, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x80, // 52.3111.........
	0x00, 0x00, 0x0f, 0x90, 0x1f, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x0f, 0xe0, // ................
	0x1f, 0x00, 0x00, 0x02, 0x05, 0x00, 0x01, 0x80, 0x01, 0x00, 0x03, 0xe0, 0x05, 0x00, 0x00, 0x03, // ................
	0x00, 0x00, 0x0f, 0x80, 0x01, 0x00, 0xe4, 0xa0, 0x00, 0x00, 0x55, 0x90, 0x04, 0x00, 0x00, 0x04, // ..........U.....
	0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0xe4, 0xa0, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0xe4, 0x80, // ................
	0x02, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0xe4, 0x80, 0x03, 0x00, 0xe4, 0xa0, // ................
	0x01, 0x00, 0x00, 0x02, 0x01, 0x00, 0x03, 0xe0, 0x00, 0x00, 0xe4, 0x90, 0xff, 0xff, 0x00, 0x00, // ................
	0x00,                                                                                           // .
};
static const uint8_t vs_gradient_dx11[434] =
{
	0x56, 0x53, 0x48, 0x05, 0x70, 0x94, 0x72, 0xf8, 0x01, 0x00, 0x0f, 0x75, 0x5f, 0x6d, 0x6f, 0x64, // VSH.p.r....u_mod
	0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, // elViewProj......
	0x88, 0x01, 0x00, 0x00, 0x44, 0x58, 0x42, 0x43, 0x9f, 0xb7, 0x11, 0x3f, 0x6d, 0xf9, 0xfc, 0xf1, // ....DXBC...?m...
	0x13, 0xc0, 0x21, 0x30, 0xc7, 0xae, 0xb9, 0x8f, 0x01, 0x00, 0x00, 0x00, 0x88, 0x01, 0x00, 0x00, // ..!0............
	0x03, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0xb8, 0x00, 0x00, 0x00, // ....,...`.......
	0x49, 0x53, 0x47, 0x4e, 0x2c, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, // ISGN,...........
	0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, //  ...............
	0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x50, 0x4f, 0x53, 0x49, 0x54, 0x49, 0x4f, 0x4e, // ........POSITION
	0x00, 0xab, 0xab, 0xab, 0x4f, 0x53, 0x47, 0x4e, 0x50, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, // ....OSGNP.......
	0x08, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, // ....8...........
	0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, // ............D...
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, // ................
	0x03, 0x0c, 0x00, 0x00, 0x53, 0x56, 0x5f, 0x50, 0x4f, 0x53, 0x49, 0x54, 0x49, 0x4f, 0x4e, 0x00, // ....SV_POSITION.
	0x54, 0x45, 0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44, 0x00, 0xab, 0xab, 0xab, 0x53, 0x48, 0x44, 0x52, // TEXCOORD....SHDR
	0xc8, 0x00, 0x00, 0x00, 0x40, 0x00, 0x01, 0x00, 0x32, 0x00, 0x00, 0x00, 0x59, 0x00, 0x00, 0x04, // ....@...2...Y...
	0x46, 0x8e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x5f, 0x00, 0x00, 0x03, // F. ........._...
	0x32, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0x00, 0x00, 0x04, 0xf2, 0x20, 0x10, 0x00, // 2.......g.... ..
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x03, 0x32, 0x20, 0x10, 0x00, // ........e...2 ..
	0x01, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x08, // ....h.......8...
	0xf2, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x56, 0x15, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, // ........V.......
	0x46, 0x8e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x0a, // F. .........2...
	0xf2, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x8e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, // ........F. .....
	0x00, 0x00, 0x00, 0x00, 0x06, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x0e, 0x10, 0x00, // ............F...
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xf2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, // ......... ......
	0x46, 0x0e, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x8e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, // F.......F. .....
	0x03, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x05, 0x32, 0x20, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, // ....6...2 ......
	0x46, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, // F.......>.......
	0x40, 0x00,                                                                                     // @.
};
static const uint8_t vs_gradient_mtl[656] =
{
	0x56, 0x53, 0x48, 0x05, 0x70, 0x94, 0x72, 0xf8, 0x01, 0x00, 0x0f, 0x75, 0x5f, 0x6d, 0x6f, 0x64, // VSH.p.r....u_mod
	0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x04, 0x01, 0x00, 0x00, 0x01, 0x00, // elViewProj......
	0x6b, 0x02, 0x00, 0x00, 0x75, 0x73, 0x69, 0x6e, 0x67, 0x20, 0x6e, 0x61, 0x6d, 0x65, 0x73, 0x70, // k...using namesp
	0x61, 0x63, 0x65, 0x20, 0x6d, 0x65, 0x74, 0x61, 0x6c, 0x3b, 0x0a, 0x73, 0x74, 0x72, 0x75, 0x63, // ace metal;.struc
	0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x49, // t xlatMtlShaderI
	0x6e, 0x70, 0x75, 0x74, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x32, 0x20, // nput {.  float2 
	0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x5b, 0x5b, 0x61, 0x74, 0x74, // a_position [[att
	0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x28, 0x30, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, // ribute(0)]];.};.
	0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x53, 0x68, // struct xlatMtlSh
	0x61, 0x64, 0x65, 0x72, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x66, // aderOutput {.  f
	0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x67, 0x6c, 0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, // loat4 gl_Positio
	0x6e, 0x20, 0x5b, 0x5b, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x5d, 0x5d, 0x3b, 0x0a, // n [[position]];.
	0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x32, 0x20, 0x76, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, //   float2 v_posit
	0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x20, 0x78, // ion;.};.struct x
	0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x55, 0x6e, 0x69, 0x66, // latMtlShaderUnif
	0x6f, 0x72, 0x6d, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x78, 0x34, // orm {.  float4x4
	0x20, 0x75, 0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, //  u_modelViewProj
	0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x76, 0x65, 0x72, 0x74, 0x65, 0x78, 0x20, 0x78, 0x6c, 0x61, 0x74, // ;.};.vertex xlat
	0x4d, 0x74, 0x6c, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, // MtlShaderOutput 
	0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x20, 0x28, 0x78, 0x6c, 0x61, // xlatMtlMain (xla
	0x74, 0x4d, 0x74, 0x6c, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x49, 0x6e, 0x70, 0x75, 0x74, 0x20, // tMtlShaderInput 
	0x5f, 0x6d, 0x74, 0x6c, 0x5f, 0x69, 0x20, 0x5b, 0x5b, 0x73, 0x74, 0x61, 0x67, 0x65, 0x5f, 0x69, // _mtl_i [[stage_i
	0x6e, 0x5d, 0x5d, 0x2c, 0x20, 0x63, 0x6f, 0x6e, 0x73, 0x74, 0x61, 0x6e, 0x74, 0x20, 0x78, 0x6c, // n]], constant xl
	0x61, 0x74, 0x4d, 0x74, 0x6c, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x55, 0x6e, 0x69, 0x66, 0x6f, // atMtlShaderUnifo
	0x72, 0x6d, 0x26, 0x20, 0x5f, 0x6d, 0x74, 0x6c, 0x5f, 0x75, 0x20, 0x5b, 0x5b, 0x62, 0x75, 0x66, // rm& _mtl_u [[buf
	0x66, 0x65, 0x72, 0x28, 0x30, 0x29, 0x5d, 0x5d, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x78, 0x6c, // fer(0)]]).{.  xl
	0x61, 0x74, 0x4d, 0x74, 0x6c, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x4f, 0x75, 0x74, 0x70, 0x75, // atMtlShaderOutpu
	0x74, 0x20, 0x5f, 0x6d, 0x74, 0x6c, 0x5f, 0x6f, 0x3b, 0x0a, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, // t _mtl_o;.  floa
	0x74, 0x34, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x20, 0x3d, 0x20, 0x30, 0x3b, // t4 tmpvar_1 = 0;
	0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, 0x7a, 0x77, 0x20, 0x3d, // .  tmpvar_1.zw =
	0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x32, 0x28, 0x30, 0x2e, 0x30, 0x2c, 0x20, 0x31, 0x2e, 0x30, //  float2(0.0, 1.0
	0x29, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, 0x78, 0x79, // );.  tmpvar_1.xy
	0x20, 0x3d, 0x20, 0x5f, 0x6d, 0x74, 0x6c, 0x5f, 0x69, 0x2e, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, //  = _mtl_i.a_posi
	0x74, 0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x20, 0x20, 0x5f, 0x6d, 0x74, 0x6c, 0x5f, 0x6f, 0x2e, 0x67, // tion;.  _mtl_o.g
	0x6c, 0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x3d, 0x20, 0x28, 0x5f, 0x6d, // l_Position = (_m
	0x74, 0x6c, 0x5f, 0x75, 0x2e, 0x75, 0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, // tl_u.u_modelView
	0x50, 0x72, 0x6f, 0x6a, 0x20, 0x2a, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x29, // Proj * tmpvar_1)
	0x3b, 0x0a, 0x20, 0x20, 0x5f, 0x6d, 0x74, 0x6c, 0x5f, 0x6f, 0x2e, 0x76, 0x5f, 0x70, 0x6f, 0x73, // ;.  _mtl_o.v_pos
	0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x3d, 0x20, 0x5f, 0x6d, 0x74, 0x6c, 0x5f, 0x69, 0x2e, 0x61, // ition = _mtl_i.a
	0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x20, 0x20, 0x72, 0x65, 0x74, // _position;.  ret
	0x75, 0x72, 0x6e, 0x20, 0x5f, 0x6d, 0x74, 0x6c, 0x5f, 0x6f, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00, // urn _mtl_o;.}...
};
extern const uint8_t* vs_gradient_pssl;
extern const uint32_t vs_gradient_pssl_size;