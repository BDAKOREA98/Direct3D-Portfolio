#pragma once

class Device : public Singleton<Device>
{
	friend class Singleton;
private:
	Device();
	~Device();

    void CreateDeviceAndSwapChain();
    void CreateBackBuffer();

public:
    void Clear();
    void Present();

    ID3D11Device*        GetDevice() { return device; }
    ID3D11DeviceContext* GetDC()     { return deviceContext; }

private:
    ID3D11Device*           device;           //무언가를 만들 때 사용, CPU를 다루는 객체
    ID3D11DeviceContext*    deviceContext;    //무언가를 그릴 때 사용, GPU를 다루는 객체
    
    IDXGISwapChain*         swapChain;        //더블버퍼링을 구현하는 객체
    ID3D11RenderTargetView* renderTargetView; //백버퍼를 관리하는 객체

    ID3D11DepthStencilView* depthStencilView;
};
