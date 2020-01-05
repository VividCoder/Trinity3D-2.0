#pragma once

#include <vector>
#include <list>

class Texture2D;

struct DrawInfo {

	float x[4];
	float y[4];
	float z;
	Texture2D* Tex;
	float r, g, b, a;

};

struct DrawList {

	std::vector<DrawInfo*> Draws;
	Texture2D* Tex;

};

class IDraw
{
public:
	IDraw();

	void Begin();

	DrawList* GetDrawList(Texture2D* tex);
	void DrawTex(int x, int y, int w, int h,Texture2D * tex,float r, float g, float b, float a);
	void End();


private:
	std::vector<DrawList*> Draws;
	float drawZ;

};

