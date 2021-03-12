#pragma once

#include <Component/SimpleScene.h>
#include <string>
#include <Core/Engine.h>

class Laborator3 : public SimpleScene
{
	public:
		Laborator3();
		~Laborator3();

		void Init() override;

	private:
		void FrameStart() override;
		void Update(float deltaTimeSeconds) override;
		void FrameEnd() override;

		void OnInputUpdate(float deltaTime, int mods) override;
		void OnKeyPress(int key, int mods) override;
		void OnKeyRelease(int key, int mods) override;
		void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
		void OnWindowResize(int width, int height) override;

	protected:
		glm::mat3 modelMatrix;
		float translateX[100], translateY[100];
		int speed[100];
		float scaleX, scaleY;
		float angularStep;
		float translateYBowandArrow;
		float rotateBow;
		int goArrow;
		float arrowMovement;
		float translateArrow;
		float rotateArrow;
		float XArrow;
		float YArrow;
		int k = 0;
		int baloon[100];
		int idx = 0;
		float rotateShuriken = 0;
		float translateXShuriken[100], translateYShuriken[100], speedShuriken[100];
		int shurikenVect[100];
		int sidx = 0;
		int lives = 0;
		int strike[100];
		int strikeidx = 0;
		int score = 0;
		int count[100];
		int leftButton = 0;
		float dim;
		int curr = 320;
		int countShu[100];
};
