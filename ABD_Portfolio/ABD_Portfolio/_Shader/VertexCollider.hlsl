#include "header.hlsli"

struct VertexInput
{
    float4 pos : POSITION;
};

struct VertexOutput
{
    float4 pos : SV_POSITION;
};

VertexOutput main(VertexInput input)
{
    VertexOutput output;
    
    output.pos = mul(input.pos, world);
    output.pos = mul(output.pos, view);
    output.pos = mul(output.pos, proj);
    
    return output;
}