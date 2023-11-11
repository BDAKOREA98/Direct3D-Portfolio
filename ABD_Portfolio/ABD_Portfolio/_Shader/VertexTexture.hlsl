cbuffer World : register(b0)
{
    matrix world;
};

cbuffer View : register(b1)
{
    matrix view;
};

cbuffer Proj : register(b2)
{
    matrix proj;
};

struct VertexInput
{
    float4 pos : POSITION;
    float2 uv : UV;
};

struct VertexOutput
{
    float4 pos : SV_POSITION;
    float2 uv : UV;
};

VertexOutput main(VertexInput input)
{
    VertexOutput output;
    
    output.pos = mul(input.pos, world);
    output.pos = mul(output.pos, view);
    output.pos = mul(output.pos, proj);
    
    output.uv = input.uv;
    
    return output;
}