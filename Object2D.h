#pragma once

#include <string>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>

namespace Object2D
{
	Mesh* CreateArrow(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color);
	Mesh* CreateBow(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color);
	Mesh* CreateBaloon(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color);
	Mesh* CreateShuriken(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color);
	Mesh* CreateHeart(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color);
	Mesh* CreateFrame(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color);
	Mesh* CreateEmptyBar(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color);
	Mesh* CreateRedX(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color);
	Mesh* CreateGreenB(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color);
	Mesh* CreatePowerBar(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color);
	Mesh* CreateOm(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color);
}

