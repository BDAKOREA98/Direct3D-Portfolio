#include "Header.hlsli"

struct VertexOutput
{
    float4 pos : SV_POSITION;
    float4 color : COLOR;
    float3 normal : NORMAL;
};

VertexOutput main(VertexColorNormal input)
{
    VertexOutput output;

    output.pos = mul(input.pos, world);
    output.pos = mul(output.pos, view);
    output.pos = mul(output.pos, proj);
    
    output.color = input.color;
    
    output.normal = normalize(mul(input.normal, (float3x3) world));
    

    return output;
}