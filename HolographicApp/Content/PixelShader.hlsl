// Per-pixel color data passed through the pixel shader.
struct PixelShaderInput
{
	min16float4 position : SV_POSITION;
	min16float2 texcoord : TEXCOORD;
};

//texture
Texture2D textureMap;
SamplerState textureSampler
{
	Filter = MIN_MAG_MIP_LINEAR;
	AddressU = Wrap;
	AddressV = Wrap;
};

min16float4 main(PixelShaderInput input) : SV_TARGET
{
	return (min16float4)textureMap.Sample(textureSampler, input.texcoord);
}