struct VertexOutput
{
    float4 pos : SV_POSITION;
    float2 uv : UV;
};

Texture2D map : register(t0);
SamplerState samp : register(s0);

float4 main(VertexOutput input) : SV_TARGET
{
    float4 tex = map.Sample(samp, input.uv);
    
    return tex;
}