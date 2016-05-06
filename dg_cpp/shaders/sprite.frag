#version 120

// Interpolated values from the vertex shaders
//varying vec2 UV;

// Values that stay constant for the whole mesh.
uniform sampler2D myTextureSampler;

void main()
{
	// Output color = color of the texture at the specified UV
	//gl_FragColor = texture2D( myTextureSampler, UV );
	gl_FragColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);
}
