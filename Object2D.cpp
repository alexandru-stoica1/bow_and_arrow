#include "Object2D.h"

#include <Core/Engine.h>
#include <iostream>

Mesh* Object2D::CreateArrow(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner + glm::vec3(0, 5 / 2, 0), glm::vec3(0.8, 0.52, 0.24)),
		VertexFormat(corner + glm::vec3(0, -5 / 2, 0), glm::vec3(0.8, 0.52, 0.24)),
		VertexFormat(corner + glm::vec3(100 / 2, 5 / 2, 0), glm::vec3(0.8, 0.52, 0.24)),
		VertexFormat(corner + glm::vec3(100 / 2, -5 / 2, 0), glm::vec3(0.8, 0.52, 0.24)),
		VertexFormat(corner + glm::vec3(120 / 2, 0, 0), glm::vec3(0.66, 0.66, 0.66)),
		VertexFormat(corner + glm::vec3(100 / 2, 10 / 2, 0), glm::vec3(0.66, 0.66, 0.66)),
		VertexFormat(corner + glm::vec3(100 / 2, -10 / 2, 0), glm::vec3(0.66, 0.66, 0.66))

	};

	Mesh* arrow = new Mesh(name);
	std::vector<unsigned short> indices = 
	{ 
		0, 1, 2,
		1, 2, 3,
		4, 5, 6
	};

	arrow->InitFromData(vertices, indices);
	return arrow;
}

Mesh* Object2D::CreateBow(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color)
{
	int x = 0, y = 0, radius = 25;

	glm::vec3 corner = leftBottomCorner;
	std::vector<VertexFormat> vertices;
	std::vector<unsigned short> indices;
	glm::vec3 center = glm::vec3(x, y, 0);
	float inc = 2 * M_PI / 100;
	
	for (float alpha = -M_PI/2; alpha < M_PI/2; alpha += inc) {
		vertices.push_back(VertexFormat(center + glm::vec3(radius * cos(alpha), radius * sin(alpha), 0), glm::vec3(0.64, 0.16, 0.16)));
	}
	
	vertices.push_back(VertexFormat(corner + glm::vec3(x, y + radius, 0), color));
	vertices.push_back(VertexFormat(corner + glm::vec3(x, y - radius, 0), color));

	Mesh* bow = new Mesh(name);

	for (int i = 0; i < vertices.size(); i++) {
		indices.push_back(i);
	}

	bow->SetDrawMode(GL_LINE_STRIP);
	glLineWidth(3);
	bow->InitFromData(vertices, indices);
	return bow;
}

Mesh* Object2D::CreateBaloon(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color)
{
	int x = 500 / 2, y = 500 / 2, radius_x = 75 / 2, radius_y = 100 / 2;

	glm::vec3 corner = leftBottomCorner;
	std::vector<VertexFormat> vertices;
	std::vector<unsigned short> indices;
	glm::vec3 center = glm::vec3(x, y, 0);
	float inc = 2 * M_PI / 1000;
	vertices.push_back(VertexFormat(center, color));
	for (float alpha = -M_PI; alpha < M_PI; alpha += inc) {
		vertices.push_back(VertexFormat(center + glm::vec3(radius_x * cos(alpha), radius_y * sin(alpha), 0), color));
	}

	for (int i = 1; i < vertices.size() - 1; i++) {
		indices.push_back(i);
		indices.push_back(0);
		indices.push_back(i + 1);
	}

	//inchid cercul
	indices.push_back(vertices.size() - 1);
	indices.push_back(0);
	indices.push_back(1);

	Mesh* bow = new Mesh(name);

	//fundita de jos
	vertices.push_back(VertexFormat(corner + glm::vec3(500 / 2, 420 / 2, 0), color));
	vertices.push_back(VertexFormat(corner + glm::vec3(525 / 2, 385 / 2, 0), color));
	vertices.push_back(VertexFormat(corner + glm::vec3(475 / 2, 385 / 2, 0), color));
	
	indices.push_back(vertices.size() - 1);
	indices.push_back(vertices.size() - 2);
	indices.push_back(vertices.size() - 3);

	//ata1
	vertices.push_back(VertexFormat(corner + glm::vec3(500 / 2, 390 / 2, 0), color));
	vertices.push_back(VertexFormat(corner + glm::vec3(510 / 2, 390 / 2, 0), color));
	vertices.push_back(VertexFormat(corner + glm::vec3(475 / 2, 375 / 2, 0), color));
	vertices.push_back(VertexFormat(corner + glm::vec3(485 / 2, 375 / 2, 0), color));

	indices.push_back(vertices.size() - 1);
	indices.push_back(vertices.size() - 2);
	indices.push_back(vertices.size() - 3);

	indices.push_back(vertices.size() - 2);
	indices.push_back(vertices.size() - 3);
	indices.push_back(vertices.size() - 4);

	//ata2
	vertices.push_back(VertexFormat(corner + glm::vec3(475 / 2, 375 / 2, 0), color));
	vertices.push_back(VertexFormat(corner + glm::vec3(485 / 2, 375 / 2, 0), color));
	vertices.push_back(VertexFormat(corner + glm::vec3(525 / 2, 350 / 2, 0), color));
	vertices.push_back(VertexFormat(corner + glm::vec3(515 / 2, 350 / 2, 0), color));

	indices.push_back(vertices.size() - 1);
	indices.push_back(vertices.size() - 2);
	indices.push_back(vertices.size() - 3);

	indices.push_back(vertices.size() - 1);
	indices.push_back(vertices.size() - 3);
	indices.push_back(vertices.size() - 4);

	//ata3
	vertices.push_back(VertexFormat(corner + glm::vec3(525 / 2, 350 / 2, 0), color));
	vertices.push_back(VertexFormat(corner + glm::vec3(515 / 2, 350 / 2, 0), color));
	vertices.push_back(VertexFormat(corner + glm::vec3(475 / 2, 325 / 2, 0), color));
	vertices.push_back(VertexFormat(corner + glm::vec3(485 / 2, 325 / 2, 0), color));

	indices.push_back(vertices.size() - 1);
	indices.push_back(vertices.size() - 2);
	indices.push_back(vertices.size() - 3);

	indices.push_back(vertices.size() - 1);
	indices.push_back(vertices.size() - 3);
	indices.push_back(vertices.size() - 4);

	//ata4
	vertices.push_back(VertexFormat(corner + glm::vec3(475 / 2, 325 / 2, 0), color));
	vertices.push_back(VertexFormat(corner + glm::vec3(485 / 2, 325 / 2, 0), color));
	vertices.push_back(VertexFormat(corner + glm::vec3(525 / 2, 300 / 2, 0), color));
	vertices.push_back(VertexFormat(corner + glm::vec3(515 / 2, 300 / 2, 0), color));

	indices.push_back(vertices.size() - 1);
	indices.push_back(vertices.size() - 3);
	indices.push_back(vertices.size() - 4);

	indices.push_back(vertices.size() - 2);
	indices.push_back(vertices.size() - 3);
	indices.push_back(vertices.size() - 1);

	glLineWidth(3);
	bow->InitFromData(vertices, indices);
	return bow;
}

Mesh* Object2D::CreateShuriken(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color)
{
	glm::vec3 corner = glm::vec3(600 / 2, 600 / 2, 0);

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(glm::vec3(600 / 2, 650 / 2, 0), color),
		VertexFormat(glm::vec3(600 / 2, 700 / 2, 0), color),
		VertexFormat(glm::vec3(650 / 2, 700 / 2, 0), color),
		VertexFormat(glm::vec3(700 / 2, 700 / 2, 0), color),
		VertexFormat(glm::vec3(700 / 2, 650 / 2, 0), color),
		VertexFormat(glm::vec3(700 / 2, 600 / 2, 0), color),
		VertexFormat(glm::vec3(650 / 2, 600 / 2, 0), color),
		VertexFormat(glm::vec3(650 / 2, 650 / 2, 0), color)
	};

	Mesh* shuriken = new Mesh(name);
	std::vector<unsigned short> indices =
	{
		0, 1, 8,
		8, 2, 3,
		8, 4, 5,
		8, 6, 7
	};

	shuriken->InitFromData(vertices, indices);
	return shuriken;
}

Mesh* Object2D::CreateHeart(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color)
{
	glm::vec3 leftcorner = glm::vec3(600, 600, 0);
	int x = 600, y = 600;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(leftcorner, color),
		VertexFormat(glm::vec3(x + 100, y, 0), color),
		VertexFormat(glm::vec3(x + 50, y - sqrt(10000 - 2500), 0), color),
		VertexFormat(glm::vec3(x + 12.5, y + sqrt(625 - 12.5 * 12.5), 0), color),
		VertexFormat(glm::vec3(x + 25, y, 0), color),
		VertexFormat(glm::vec3(x + 37.5, y + sqrt(625 - 12.5 * 12.5), 0), color),
		VertexFormat(glm::vec3(x + 50, y, 0), color),
		VertexFormat(glm::vec3(x + 62.5, y + sqrt(625 - 12.5 * 12.5), 0), color),
		VertexFormat(glm::vec3(x + 75, y, 0), color),
		VertexFormat(glm::vec3(x + 87.5, y + sqrt(625 - 12.5 * 12.5), 0), color),
	};

	Mesh* heart = new Mesh(name);
	std::vector<unsigned short> indices =
	{
		0, 1, 2,
		0, 3, 4,
		4, 5, 6,
		3, 4, 5,
		6, 7, 8,
		8, 9, 1,
		7, 8, 9
	};

	heart->InitFromData(vertices, indices);
	return heart;
}

Mesh* Object2D::CreateFrame(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color)
{
	glm::vec3 leftcorner = glm::vec3(0, 0, 0);
	int x = 0, y = 0;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(leftcorner, color),
		VertexFormat(glm::vec3(1280, 0, 0), color),
		VertexFormat(glm::vec3(0, 100, 0), color),
		VertexFormat(glm::vec3(1280, 100, 0), color)
	};

	Mesh* frame = new Mesh(name);
	std::vector<unsigned short> indices =
	{
		0, 1, 2,
		1, 2, 3
	};

	frame->InitFromData(vertices, indices);
	return frame;
}

Mesh* Object2D::CreateEmptyBar(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color)
{
	glm::vec3 leftcorner = glm::vec3(320, 25, 0);
	int x = 320, y = 25;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(leftcorner, color),
		VertexFormat(glm::vec3(x + 640, y, 0), color),
		VertexFormat(glm::vec3(x, y + 50, 0), color),
		VertexFormat(glm::vec3(x + 640, y + 50, 0), color)
	};

	Mesh* emptyBar = new Mesh(name);
	std::vector<unsigned short> indices =
	{
		0, 1, 2,
		1, 2, 3
	};

	emptyBar->InitFromData(vertices, indices);
	return emptyBar;
}

Mesh* Object2D::CreateRedX(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color)
{
	glm::vec3 leftcorner = glm::vec3(50, 25, 0);
	int x = 50, y = 25;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(leftcorner, color),
		VertexFormat(glm::vec3(x + 20, y, 0), color),
		VertexFormat(glm::vec3(x + 70, y + 50, 0), color),
		VertexFormat(glm::vec3(x + 90, y + 50, 0), color),

		VertexFormat(glm::vec3(x + 70, y, 0), color),
		VertexFormat(glm::vec3(x + 90, y, 0), color),
		VertexFormat(glm::vec3(x + 20, y + 50, 0), color),
		VertexFormat(glm::vec3(x, y + 50, 0), color)
	};

	Mesh* redX = new Mesh(name);
	std::vector<unsigned short> indices =
	{
		0, 1, 2,
		1, 3, 2,
		4, 5, 7,
		4, 7, 6
	};

	redX->InitFromData(vertices, indices);
	return redX;
}

Mesh* Object2D::CreateGreenB(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color)
{
	glm::vec3 leftcorner = glm::vec3(50, 25, 0);
	int x = 50, y = 25;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(leftcorner, color),
		VertexFormat(glm::vec3(x + 20, y, 0), color),
		VertexFormat(glm::vec3(x + 70, y + 50, 0), color),
		VertexFormat(glm::vec3(x + 90, y + 50, 0), color),

		VertexFormat(glm::vec3(x - 20, y + 25, 0), color),
		VertexFormat(glm::vec3(x, y + 25, 0), color)
	};

	Mesh* greenB = new Mesh(name);
	std::vector<unsigned short> indices =
	{
		0, 1, 2,
		1, 3, 2,
		0, 4, 5,
		1, 0, 5
	};

	greenB->InitFromData(vertices, indices);
	return greenB;
}

Mesh* Object2D::CreatePowerBar(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color)
{
	glm::vec3 leftcorner = glm::vec3(320, 25, 0);
	int x = 320, y = 25;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(leftcorner, color),
		VertexFormat(glm::vec3(x + 2, y, 0), color),
		VertexFormat(glm::vec3(x, y + 50, 0), color),
		VertexFormat(glm::vec3(x + 2, y + 50, 0), color)
	};

	Mesh* powerBar = new Mesh(name);
	std::vector<unsigned short> indices =
	{
		0, 1, 2,
		1, 2, 3
	};

	powerBar->InitFromData(vertices, indices);
	return powerBar;
}

Mesh* Object2D::CreateOm(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color)
{
	glm::vec3 leftcorner = glm::vec3(300, 300, 0);
	int x = 300, y = 300;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(leftcorner, color),
		VertexFormat(glm::vec3(x, y + 50, 0), color),
		VertexFormat(glm::vec3(x + 10, y + 50, 0), color),
		VertexFormat(glm::vec3(x + 10, y, 0), color),

		
		VertexFormat(glm::vec3(x + 5, y, 0), color),
		VertexFormat(glm::vec3(x, y - 25, 0), color),
		VertexFormat(glm::vec3(x + 4, y - 25, 0), color),


		VertexFormat(glm::vec3(x + 6, y - 25, 0), color),
		VertexFormat(glm::vec3(x + 10, y - 25, 0), color),


		VertexFormat(glm::vec3(x - 5, y + 50, 0), color),
		VertexFormat(glm::vec3(x + 15, y + 50, 0), color),
		VertexFormat(glm::vec3(x - 5, y + 75, 0), color),
		VertexFormat(glm::vec3(x + 15, y + 75, 0), color),
	};

	Mesh* powerBar = new Mesh(name);
	std::vector<unsigned short> indices =
	{
		0, 2, 1,
		0, 3, 2,
		4, 5, 6,
		4, 7, 8,
		9, 10, 11,
		10, 11, 12
	};

	powerBar->InitFromData(vertices, indices);
	return powerBar;
}