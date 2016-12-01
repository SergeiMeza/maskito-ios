// Geometric Tools LLC, Redmond WA 98052
// Copyright (c) 1998-2015
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
// File Version: 2.0.0 (2015/09/23)

#pragma once

#include <Graphics/GteShader.h>
#include <Graphics/DX11/GteDX11Shader.h>

namespace gte
{

class GTE_IMPEXP DX11PixelShader : public DX11Shader
{
public:
    // Construction and destruction.
    virtual ~DX11PixelShader();
    DX11PixelShader(ID3D11Device* device, Shader const* shader);
    static DX11GraphicsObject* Create(ID3D11Device* device,
        GraphicsObject const* object);

    // Overrides to hide DX11 shader functions that have "PS" embedded in
    // their names.

    // Calls to ID3D11DeviceContext::PSSetShader.
    virtual void Enable(ID3D11DeviceContext* context);
    virtual void Disable(ID3D11DeviceContext* context);

    // Calls to ID3D11DeviceContext::PSSetConstantBuffers.
    virtual void EnableCBuffer(ID3D11DeviceContext* context,
        unsigned int bindPoint, ID3D11Buffer* buffer);
    virtual void DisableCBuffer(ID3D11DeviceContext* context,
        unsigned int bindPoint);

    // Calls to ID3D11DeviceContext::PSSetShaderResources.
    virtual void EnableSRView(ID3D11DeviceContext* context,
        unsigned int bindPoint, ID3D11ShaderResourceView* srView);
    virtual void DisableSRView(ID3D11DeviceContext* context,
        unsigned int bindPoint);

    // Calls to ID3D11DeviceContext::PSSetUnorderedAccessViews.
    virtual void EnableUAView(ID3D11DeviceContext* context,
        unsigned int bindPoint, ID3D11UnorderedAccessView* uaView,
        unsigned int initialCount);
    virtual void DisableUAView(ID3D11DeviceContext* context,
        unsigned int bindPoint);

    // Calls to ID3D11DeviceContext::PSSetSamplers.
    virtual void EnableSampler(ID3D11DeviceContext* context,
        unsigned int bindPoint, ID3D11SamplerState* state);
    virtual void DisableSampler(ID3D11DeviceContext* context,
        unsigned int bindPoint);
};

}