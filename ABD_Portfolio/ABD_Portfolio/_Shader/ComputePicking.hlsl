cbuffer Ray : register(b0)
{
    float3 origin;
    uint outputSize;
    
    float3 direction;
};

struct InputDesc
{
    uint index;
    
    float3 v0;
    float3 v1;
    float3 v2;
};

struct OutputDesc
{
    int isPicked;
    
    float u;
    float v;
    
    float distance;
};

StructuredBuffer<InputDesc> input : register(t0);
RWStructuredBuffer<OutputDesc> output : register(u0);

void Intersects(uint index)
{
    float3 v0 = input[index].v0;
    float3 v1 = input[index].v1;
    float3 v2 = input[index].v2;
    
    float3 v01 = v1 - v0;
    float3 v02 = v2 - v0;
    
    float3 P, T, Q;
    
    P = cross(direction, v02);
    
    float d = 1.0f / dot(v01, P);
    
    T = origin - v0;
    output[index].u = dot(T, P) * d;
    
    Q = cross(T, v01);
    output[index].v = dot(direction, Q) * d;
    output[index].distance = dot(v02, Q) * d;
    
    bool bIntersect = (output[index].u >= 0.0f) &&
                      (output[index].v >= 0.0f) &&
                      (output[index].u + output[index].v <= 1.0f) &&
                      (output[index].distance >= 0.0f);
    
    output[index].isPicked = bIntersect;
}

[numthreads(32, 32, 1)]
void main(uint3 groupID : SV_GroupID, uint groupIndex : SV_GroupIndex)
{
    uint index = groupID.x * 32 * 32 + groupIndex;
    
    if (outputSize > index)
        Intersects(index);
}