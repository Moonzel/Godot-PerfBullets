shader_type canvas_item;

//seperates the texture into frames, this is automatically done, please do not input anythnig for these
uniform float col; //float for performance sake, never input a float here, only ints
uniform float row;

varying vec4 custom; //visiblity, offsetx, offsety

void vertex() {
	custom = INSTANCE_CUSTOM;
}

void fragment() {
//	COLOR = vec4(custom.r, custom.g, custom.b, 1.0);
	if (custom.r == 1.0) {
		if (col == 0.0 && row == 0.0) {
			COLOR = texture(TEXTURE, UV);
		}
		else {
			vec2 uv = UV;
			uv = vec2(uv.x/row, uv.y/col);
			uv.y += custom.b/col;//col and row must be floats, wrap them if you plan on using ints
			uv.x += custom.g/row;
			COLOR = texture(TEXTURE, uv);
		}
	}
	else {
		COLOR = vec4(0.0,0.0,0.0,0.0);
	}
}
