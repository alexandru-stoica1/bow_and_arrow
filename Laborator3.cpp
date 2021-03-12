#include "Laborator3.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>
#include "Transform2D.h"
#include "Object2D.h"

using namespace std;

Laborator3::Laborator3()
{
}

Laborator3::~Laborator3()
{
}

void Laborator3::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);
	//
	//cout << resolution.x << ' ' << resolution.y;
	//1280x720
	glm::vec3 corner = glm::vec3(0, 0, 0);
	float squareSide = 100;

	// compute coordinates of square center
	float cx = corner.x + squareSide / 2;
	float cy = corner.y + squareSide / 2;
	
	// initialize tx and ty (the translation steps)
	for (int i = 0; i < 100; i++)
	{
		translateX[i] = 0;
		translateY[i] = 0;
	}
	
	translateYBowandArrow = 0;
	goArrow = 0;
	arrowMovement = 0;
	translateArrow = 0;

	// initialize angularStep
	angularStep = 0;

	Mesh* arrow = Object2D::CreateArrow("arrow", corner, squareSide, glm::vec3(0, 0, 0));
	AddMeshToList(arrow);

	Mesh* bow = Object2D::CreateBow("bow", corner, squareSide, glm::vec3(0, 0, 0));
	AddMeshToList(bow);

	Mesh* baloon_green = Object2D::CreateBaloon("baloon_green", corner, squareSide, glm::vec3(1, 0, 0));
	AddMeshToList(baloon_green);

	Mesh* baloon_blue = Object2D::CreateBaloon("baloon_blue", corner, squareSide, glm::vec3(1, 1, 0));
	AddMeshToList(baloon_blue);

	Mesh* shuriken = Object2D::CreateShuriken("shuriken", corner, squareSide, glm::vec3(0, 0, 1));
	AddMeshToList(shuriken);

	Mesh* heart = Object2D::CreateHeart("heart", corner, squareSide, glm::vec3(1, 0, 0));
	AddMeshToList(heart);

	Mesh* frame = Object2D::CreateFrame("frame", corner, squareSide, glm::vec3(0.7, 0.7, 0.7));
	AddMeshToList(frame);

	Mesh* emptyBar = Object2D::CreateEmptyBar("emptyBar", corner, squareSide, glm::vec3(1, 1, 1));
	AddMeshToList(emptyBar);

	Mesh* redX = Object2D::CreateRedX("redX", corner, squareSide, glm::vec3(1, 0, 0));
	AddMeshToList(redX);

	Mesh* greenB = Object2D::CreateGreenB("greenB", corner, squareSide, glm::vec3(0, 1, 0));
	AddMeshToList(greenB);

	Mesh* powerBar = Object2D::CreatePowerBar("powerBar", corner, squareSide, glm::vec3(1, 0.25, 1));
	AddMeshToList(powerBar);

	Mesh* om = Object2D::CreateOm("om", corner, squareSide, glm::vec3(1, 1, 1));
	AddMeshToList(om);

	for (int i = 0; i < 100; i++)
	{
		int x = rand() % 700 + 400, y = rand() % 200000, speed1 = rand() % 100 + 100;
		translateX[i] = x;
		translateY[i] = -y;
		speed[i] = speed1;
		count[i] = 0;
	}

	for (int i = 0; i < 100; i++)
	{
		int x = rand() % 200000 + 2000, y = rand() % 650, speed1 = rand() % 200 + 100;
		translateXShuriken[i] = x;
		translateYShuriken[i] = y;
		speedShuriken[i] = speed1;
		countShu[i] = 0;
	}
	
	dim = 0;
}

void Laborator3::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 1, 0.9, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}

void Laborator3::Update(float deltaTimeSeconds)
{
	if (translateYBowandArrow < 100)
	{
		modelMatrix = glm::mat3(1);
		RenderMesh2D(meshes["redX"], shaders["VertexColor"], modelMatrix);
	}
	else 
	{
		modelMatrix = glm::mat3(1);
		RenderMesh2D(meshes["greenB"], shaders["VertexColor"], modelMatrix);
	}

	modelMatrix = glm::mat3(1);

	if (leftButton == 1 && dim < 320 && goArrow == 0)
	{
		dim += deltaTimeSeconds * 200;
	}

	modelMatrix *= Transform2D::Translate(320, 25);
	modelMatrix *= Transform2D::Scale(dim, 1);
	modelMatrix *= Transform2D::Translate(-320, -25);
	RenderMesh2D(meshes["powerBar"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["emptyBar"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	if (lives == 3)
	{
		modelMatrix *= Transform2D::Scale(0.000000005, 0.000000005);
		std::cout << "final score:" << score << endl << "GAME OVER!";
		exit(0);
	}
	modelMatrix *= Transform2D::Translate(300, 0);
	modelMatrix *= Transform2D::Scale(0.75, 0.75);
	modelMatrix *= Transform2D::Translate(570, -500);
	RenderMesh2D(meshes["heart"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	if (lives == 2)
	{
		modelMatrix *= Transform2D::Scale(0.000000005, 0.000000005);
	}
	modelMatrix *= Transform2D::Translate(300, 0);
	modelMatrix *= Transform2D::Scale(0.75, 0.75);
	modelMatrix *= Transform2D::Translate(460, -500);
	RenderMesh2D(meshes["heart"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	if (lives == 1 || lives == 2)
	{
		modelMatrix *= Transform2D::Scale(0.000000005, 0.000000005);
	}
	modelMatrix *= Transform2D::Translate(300, 0);
	modelMatrix *= Transform2D::Scale(0.75, 0.75);
	modelMatrix *= Transform2D::Translate(350 , -500);
	RenderMesh2D(meshes["heart"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["frame"], shaders["VertexColor"], modelMatrix);
	
	modelMatrix *= Transform2D::Translate(5, translateYBowandArrow);
	modelMatrix *= Transform2D::Translate(-300, -325);
	RenderMesh2D(meshes["om"], shaders["VertexColor"], modelMatrix);

	for (int i = 0; i < 100; i++)
	{	
		modelMatrix = glm::mat3(1);
		for (int j = 0; j < idx; j++)
		{
			if (i == baloon[j])
			{
				modelMatrix *= Transform2D::Translate(translateX[i] + 250, translateY[i] + 250);
				modelMatrix *= Transform2D::Scale(0.5, 0.5);
				modelMatrix *= Transform2D::Translate(-translateX[i] - 250, -translateY[i] - 250);
				if (count[i] == 0)
				{
					if (i % 2 == 0)
					{
						score += 1;
					}
					else
					{
						score -= 1;
					}
					std::cout << "score: " << score << endl;
				}
				count[i] = 1;
			}
		}
		
		if (count[i] == 0)
		{
			translateY[i] += speed[i] * deltaTimeSeconds;
			modelMatrix *= Transform2D::Translate(translateX[i], translateY[i]);
		}
		else
		{
			translateY[i] -= 3 * speed[i] * deltaTimeSeconds;
			modelMatrix *= Transform2D::Translate(translateX[i], translateY[i]);
		}
		if (sqrt((XArrow + cos(rotateArrow) * 60 - (translateX[i] + 250)) * (XArrow + cos(rotateArrow) * 60 - (translateX[i] + 250)) + (YArrow + sin(rotateArrow) * 60 - (translateY[i] + 250)) * (YArrow + sin(rotateArrow) * 60 - (translateY[i] + 250))) < 50)
		{
			YArrow = translateYBowandArrow;
			XArrow = 10;
			dim = 1;
			baloon[idx++] = i;
			goArrow = 0;
			arrowMovement = 0;
			translateArrow = translateYBowandArrow;
			rotateArrow = rotateBow;
		}

		if (i % 2 == 0)
			RenderMesh2D(meshes["baloon_green"], shaders["VertexColor"], modelMatrix);
		else 
			RenderMesh2D(meshes["baloon_blue"], shaders["VertexColor"], modelMatrix);
	}

	modelMatrix = Transform2D::Translate(10, translateYBowandArrow) * Transform2D::Rotate(rotateBow) * glm::mat3(1);
	RenderMesh2D(meshes["bow"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);

	if (goArrow == 1)
	{	
		arrowMovement += dim * 10 * deltaTimeSeconds;
		float dx = cos(rotateArrow) * arrowMovement;
		float dy = sin(rotateArrow) * arrowMovement;
		XArrow = 10 + dx;
		YArrow = translateArrow + dy;
		modelMatrix *= Transform2D::Translate(dx, dy) * Transform2D::Translate(10, translateArrow) * Transform2D::Rotate(rotateArrow);
	}
	else
	{
		modelMatrix *= Transform2D::Translate(10, translateYBowandArrow) * Transform2D::Rotate(rotateBow) * glm::mat3(1);
	}

	if (arrowMovement > 1280 || YArrow > 720 || YArrow < 100)
	{	
		YArrow = translateYBowandArrow;
		XArrow = 10;
		goArrow = 0;
		arrowMovement = 0;
		translateArrow = translateYBowandArrow;
		rotateArrow = rotateBow;
		dim = 1;
	}
	RenderMesh2D(meshes["arrow"], shaders["VertexColor"], modelMatrix);
	



	for (int i = 0; i < 100; i++)
	{
		int ver = 0;
		modelMatrix = glm::mat3(1);
		for (int j = 0; j < sidx; j++)
		{
			if (i == shurikenVect[j])
			{	
				ver = 1;

				modelMatrix *= Transform2D::Translate(translateXShuriken[i], translateYShuriken[i]);
				modelMatrix *= Transform2D::Scale(0.5, 0.5);
				modelMatrix *= Transform2D::Translate(-translateXShuriken[i], -translateYShuriken[i]);

				if (countShu[i] == 0)
				{
					score += 1;
					std::cout << "score: " << score << endl;
				}
				countShu[i] = 1;
			}
		}
		rotateShuriken += deltaTimeSeconds;
		translateXShuriken[i] -= speedShuriken[i] * deltaTimeSeconds;
		modelMatrix *= Transform2D::Translate(translateXShuriken[i], translateYShuriken[i]) * Transform2D::Rotate(rotateShuriken) * Transform2D::Translate(-325, -325);
		RenderMesh2D(meshes["shuriken"], shaders["VertexColor"], modelMatrix);
		
		if (ver == 0)
			if (sqrt((XArrow + cos(rotateArrow) * 60 - (translateXShuriken[i])) * (XArrow + cos(rotateArrow) * 60 - (translateXShuriken[i])) + (YArrow + sin(rotateArrow) * 60 - (translateYShuriken[i])) * (YArrow + sin(rotateArrow) * 60 - (translateYShuriken[i]))) < 25)
			{
				YArrow = translateYBowandArrow;
				XArrow = 10;
				dim = 1;
				shurikenVect[sidx++] = i;
				goArrow = 0;
				arrowMovement = 0;
				translateArrow = translateYBowandArrow;
				rotateArrow = rotateBow;
			}

		if (ver == 0)
			if (sqrt((10 - (translateXShuriken[i])) * (10 - (translateXShuriken[i])) + (translateYBowandArrow - (translateYShuriken[i])) * (translateYBowandArrow - (translateYShuriken[i]))) < 50)
			{
				int ok = 0;
				for (int j = 0; j < strikeidx; j++)
				{
					if (strike[j] == i)
						ok++;
				}

				if (ok == 0)
				{
					lives++;
					strike[strikeidx++] = i;
				}
			}
	}
}

 
void Laborator3::FrameEnd()
{

}

void Laborator3::OnInputUpdate(float deltaTime, int mods)
{
	
	if (window->KeyHold(GLFW_KEY_W) && translateYBowandArrow <= 695)
	{
		translateYBowandArrow += 600 * deltaTime;
		if (goArrow == 0)
			translateArrow = translateYBowandArrow;
	}
	if (window->KeyHold(GLFW_KEY_S) && translateYBowandArrow >= 125)
	{
		translateYBowandArrow -= 600 * deltaTime;

		if (goArrow == 0)
			translateArrow = translateYBowandArrow;
	}
}

void Laborator3::OnKeyPress(int key, int mods)
{
	// add key press event
}

void Laborator3::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Laborator3::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
	
	int newY = 720 - mouseY;
	if (mouseX != 200)
		rotateBow = atan((float)(newY - 200) /(mouseX - 10));
	if (goArrow == 0)
		rotateArrow = rotateBow;
}

void Laborator3::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
	if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT))
	{
		leftButton = 1;
	}
}

void Laborator3::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	goArrow = 1;
	leftButton = 0;
}

void Laborator3::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Laborator3::OnWindowResize(int width, int height)
{
}
