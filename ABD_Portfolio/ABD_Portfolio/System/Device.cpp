#include "Framework.h"
#include "Device.h"

Device::Device()
{
    CreateDeviceAndSwapChain();
    CreateBackBuffer();
}

Device::~Device()
{
    device->Release();
    deviceContext->Release();
    swapChain->Release();
    renderTargetView->Release();
    depthStencilView->Release();
}

void Device::CreateDeviceAndSwapChain()
{
    DXGI_SWAP_CHAIN_DESC swapChainDesc = {};

    swapChainDesc.BufferCount = 1;

    swapChainDesc.BufferDesc.Width = WIN_WIDTH;
    swapChainDesc.BufferDesc.Height = WIN_HEIGHT;
    swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    //RGBA 8비트 * 4개 = 32비트, UNORM = Unsigned Normal = 0 ~ 1 

    swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
    swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;

    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

    swapChainDesc.OutputWindow = hWnd;

    swapChainDesc.SampleDesc.Count = 1;
    swapChainDesc.SampleDesc.Quality = 0;

    swapChainDesc.Windowed = true;

    D3D11CreateDeviceAndSwapChain
    (
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        0,
        D3D11_CREATE_DEVICE_DEBUG,
        nullptr,
        0,
        D3D11_SDK_VERSION,
        &swapChainDesc,
        &swapChain,
        &device,
        nullptr,
        &deviceContext
    );
}

void Device::CreateBackBuffer()
{
    ID3D11Texture2D* backBuffer;

    swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);

    device->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView);

    backBuffer->Release();

    //DSV

    ID3D11Texture2D* depthBuffer;

    D3D11_TEXTURE2D_DESC depthDesc;

    depthDesc.Width = WIN_WIDTH;
    depthDesc.Height = WIN_HEIGHT;
    depthDesc.MipLevels = 1;
    depthDesc.ArraySize = 1;
    depthDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    depthDesc.SampleDesc.Count = 1;
    depthDesc.SampleDesc.Quality = 0;
    depthDesc.Usage = D3D11_USAGE_DEFAULT;
    depthDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    depthDesc.CPUAccessFlags = 0;
    depthDesc.MiscFlags = 0;

    device->CreateTexture2D(&depthDesc, nullptr, &depthBuffer);

    D3D11_DEPTH_STENCIL_VIEW_DESC dsvDesc = {};

    dsvDesc.Format = depthDesc.Format;
    dsvDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;

    device->CreateDepthStencilView(depthBuffer, &dsvDesc, &depthStencilView);

    depthBuffer->Release();

}

void Device::Clear()
{
    deviceContext->OMSetRenderTargets(1, &renderTargetView, depthStencilView);

    float clearColor[4] = { 0.33f, 0.33f, 0.4f, 1.0f };

    deviceContext->ClearRenderTargetView(renderTargetView, clearColor);
    deviceContext->ClearDepthStencilView(depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

void Device::Present()
{
    swapChain->Present(0, 0);
}
