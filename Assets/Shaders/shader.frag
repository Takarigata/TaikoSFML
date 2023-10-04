uniform sampler2D current; //set this to sf::Shader::CurrentTexture as explained in the tutorials

void main()
{
  vec2 thisposition = gl_TexCoord[0].xy;
  float alpha = 0.5;  //this is the y coordinate, from 0 to 1
  vec4 pixel = texture2D(current, gl_TexCoord[0].xy);
  pixel.a = alpha;
  gl_FragColor = pixel;
}