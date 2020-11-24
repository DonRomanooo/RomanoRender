#pragma once
#include "vec3.h"
#include <OpenImageIO/imagebuf.h>

#ifndef MATERIAL
#define MATERIAL


class material
{
public:
    material() {}

    material(int &id) :
        mat_id(id)
    {
    }

    material(int& id, vec3 color_parm, vec3 n, bool is_light) :
        clr(color_parm),
        normal(n),
        islight(is_light)
    {        
    }

    material(int& id, vec3 color_parm, float _roughness, float _refrac) :
        clr(color_parm),
        roughness(_roughness),
        refraction(_refrac)
    {
        diffuse_roughness = 0.0f;
        specular = 0.0f;
        metallic = 0.0f;
        ior = vec3(1.5f);
        reflection_color = vec3(1.0f);
    }


public:
    int mat_id;
    bool islight;
    vec3 normal;

    vec3 clr;
    float diffuse_roughness;

    float roughness;
    vec3 reflection_color;

    float refraction;
    float refraction_roughness;
    vec3 refraction_color;

    float metallic;
    float specular;
    vec3 ior;
};


OIIO::ImageBuf load_texture(const char* path)
{
    OIIO::ImageBuf tex(path);
    return tex;
}

vec3 get_tex_pixel(OIIO::ImageBuf& tex, int x, int y)
{
    float pixel[3];
    tex.OIIO::ImageBuf::getpixel(x, y, 0, pixel);
    return vec3(pixel[0], pixel[1], pixel[2]);
}

#endif