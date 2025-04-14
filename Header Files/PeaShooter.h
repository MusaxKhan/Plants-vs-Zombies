//#pragma once
//#include "Plant.h"
//#include <iostream>
//#include "Pea.h"
//#include "Static Sun.h"
//#include "Zombie Factoryr.h"
//using namespace std;
//using namespace sf;
//
//class PeaShooter : public Plant
//{
//	Pea* pea;
//	Sprite peashooter;
//	int fire_rate;
//	int damage;
//	Clock fire_timer;
//	bool pea_exists;
//	bool pea_exists2;
//	bool made;
//	int counter;
//	bool fired = false;
//
//public:
//	PeaShooter()
//	{
//		fired = false;
//		counter = 0;
//		fire_rate = 5;
//		Image pea_i;
//		pea_i.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/peashooter.png");
//		Texture pea_t;
//		pea_t.loadFromImage(pea_i);
//		peashooter.setTexture(pea_t);
//		pea_exists = false;
//		pea_exists2 = false;
//		made = false;
//	}
//	void draw_on(RenderWindow& window)
//	{
//		if (exists)
//		{
//			Image pea_i;
//			pea_i.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/peashooter.png");
//			Texture pea_t;
//			pea_t.loadFromImage(pea_i);
//			peashooter.setTexture(pea_t);
//			peashooter.setPosition(getX(), getY());
//			window.draw(peashooter);
//		}
//		else
//			peashooter.setPosition(10000, 10000);
//	}
//	void update(RenderWindow& window, Zombie_Factory** zfacs, int types_of_zombies, patch grid[][9], int &score)
//	{
//		Time elapsed = fire_timer.getElapsedTime();
//		if (elapsed.asSeconds() > 0.005)
//		{
//			fire(window);
//			if(fired)
//			{
//				for (int i = 0; i < types_of_zombies; i++)
//				{
//					for (int j = 0; j < zfacs[i]->numZombies; j++)
//					{
//						if (pea->getX() > zfacs[i]->zombies[j]->current_x - 40 && pea->getX() < zfacs[i]->zombies[j]->current_x)
//						{
//							if (pea->getY() == zfacs[i]->zombies[j]->current_y)
//							{
//								// Here decide what will happen to the Zombie
//								pea_exists2 = false;
//								//pea->set(1000, 10000);
//								pea->setY(pea->getY() + 10000);
//							}
//						}
//					}
//				}
//				pea->covered_distance = pea->getX() - pea->first_x;
//			}
//			fire_timer.restart();
//		}
//		if (pea_exists && pea->covered_distance >= 1000)
//		{
//			delete pea;
//			pea_exists = false;
//			fired = false;
//			pea->covered_distance = 0;
//		}
//	}
//	void attack()
//	{
//		cout << "PeaShooter will attack" << endl;
//	}
//	void disappear()
//	{
//		cout << "Pea Sooter will disappear" << endl;
//	}
//	void fire(RenderWindow& window)
//	{
//		if (!pea_exists)
//		{
//			if (made)
//			{
//				if (counter > 0)
//				{
//					pea = new Pea(fire_rate, getX(), getY());
//					pea_exists = true;
//					pea_exists2 = true;
//					counter = 0;
//					fired = true;
//				}
//			}
//			else
//				if (counter > 70)
//				{
//					pea = new Pea(fire_rate, getX(), getY());
//					pea_exists = true;
//					pea_exists2 = true;
//					counter = 0;
//					fired = true;
//					made = true;
//				}
//			counter++;
//		}
//		else
//		{
//			pea->update(window, pea_exists2);
//		}
//	}
//	void setCoordinates(int* cor, bool alpha = false)
//	{
//		setX(cor[0]);
//		setY(cor[1]);
//	}
//	void Start_Moving(RenderWindow& window, patch grid[][9])
//	{
//
//	}
//	Sprite get_Sprite()
//	{
//		return peashooter;
//	}
//	Pea* get_Bullet()
//	{
//		return pea;
//	}
//	
//	~PeaShooter()
//	{
//		cout<<"Destructed"<<endl;
//	}
//};
//
//class Sunflower: public Plant
//{
//	Static_Sun* sun;
//	Sprite sunflower;
//	int spwan_rate;
//	bool sun_exists;
//	Clock sun_timer;
//	Clock de_spwan;
//public:
//	Sunflower()
//	{
//		Image sun_i;
//		sun_i.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/img2.png");
//		Texture sun_t;
//		sun_t.loadFromImage(sun_i);
//		sunflower.setTexture(sun_t);
//		sun_exists = false;
//	}
//	void draw_on(RenderWindow& window)
//	{
//		if (exists)
//		{
//			Image sun_i;
//			sun_i.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/img2.png");
//			Texture sun_t;
//			sun_t.loadFromImage(sun_i);
//			sunflower.setTexture(sun_t);
//			sunflower.setPosition(getX(), getY());
//			window.draw(sunflower);
//		}
//		else
//			sunflower.setPosition(10000, 10000);
//	}
//	void update(RenderWindow& window, Zombie_Factory** zfacs, int types_of_zombies, patch grid[][9], int& score)
//	{
//		Time despawn_sun = de_spwan.getElapsedTime();
//		if (sun_exists)
//		{
//			if (Mouse::isButtonPressed(Mouse::Left))
//			{
//				if (sun->isTouched(Mouse::getPosition().x, Mouse::getPosition().y, sun->getSprite()))
//				{
//					sun_exists = false;
//					Score(score);
//				}
//			}
//			if (despawn_sun.asSeconds() > 5)  // If not touched for 5 seconds, set sun_exists to false
//			{
//				sun_exists = false;
//				de_spwan.restart();
//				sun_timer.restart();
//			}
//			if(sun_exists)
//			sun->spawn_Sun(window);
//		}
//		
//		Time elapsed_time = sun_timer.getElapsedTime();
//		if (elapsed_time.asSeconds() > 9 && !sun_exists)
//		{
//			sun = new Static_Sun(window, getX()+60, getY()+60);
//			sun_exists = true;
//			sun_timer.restart();
//			de_spwan.restart();
//		}
//	}
//	void setCoordinates(int* cor, bool alpha = false)
//	{
//		setX(cor[0]);
//		setY(cor[1]);
//	}
//	void Start_Moving(RenderWindow& window, patch grid[][9])
//	{}
//	Sprite get_Sprite()
//	{
//		return sunflower;
//	}
//	void attack()
//	{
//		cout << "PeaShooter will attack" << endl;
//	}
//	void disappear()
//	{
//		cout << "Pea Sooter will disappear" << endl;
//	}
//};
//
//class Repeater : public Plant
//{
//	Pea* pea1;
//	Pea* pea2;
//	Sprite repeater;
//	int health;
//	int fire_rate;
//	bool pea_exists[2];
//	bool pea_exists2[2];
//	bool fired[2];
//	Clock fire_timer;
//	int counter[2];
//	bool made[2];
//public:
//	Repeater()
//	{
//		fire_rate = 5;
//		Image rep_i;
//		rep_i.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/repeater.png");
//		Texture rep_t;
//		rep_t.loadFromImage(rep_i);
//		repeater.setTexture(rep_t);
//		pea_exists[0] = false;
//		pea_exists[1] = false;
//		pea_exists2[0] = false;
//		pea_exists2[1] = false;
//		fired[0] = false;
//		fired[1] = false;
//		counter[0] = 0;
//		counter[1] = 0;
//		made[0] = false;
//		made[1] = false;
//	}
//	void draw_on(RenderWindow& window)
//	{
//		if (exists)
//		{
//			Image rep_i;
//			rep_i.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/repeater.png");
//			Texture rep_t;
//			rep_t.loadFromImage(rep_i);
//			repeater.setTexture(rep_t);
//			repeater.setPosition(getX(), getY());
//			window.draw(repeater);
//		}
//		else
//			repeater.setPosition(10000, 10000);
//	}
//	void update(RenderWindow& window, Zombie_Factory** zfacs, int types_of_zombies, patch grid[][9], int& score)
//	{
//		Time elapsed = fire_timer.getElapsedTime();
//		if (elapsed.asSeconds() > 0.005)
//		{
//			fire(window);
//			if (fired[0])
//			{
//				for (int i = 0; i < types_of_zombies; i++)
//				{
//					for (int j = 0; j < zfacs[i]->numZombies; j++)
//					{
//						if (pea1->getX() > zfacs[i]->zombies[j]->current_x - 40 && pea1->getX() < zfacs[i]->zombies[j]->current_x)
//						{
//							if (pea1->getY() == zfacs[i]->zombies[j]->current_y)
//							{
//								// Here decide what will happen to the Zombie
//								pea_exists2[0] = false;
//								pea1->setY(pea1->getY() + 10000);
//							}
//						}
//					}
//				}
//				pea1->covered_distance = pea1->getX() - pea1->first_x;
//			}
//			if (fired[1])
//			{
//				for (int i = 0; i < types_of_zombies; i++)
//				{
//					for (int j = 0; j < zfacs[i]->numZombies; j++)
//					{
//						if (pea2->getX() > zfacs[i]->zombies[j]->current_x - 40 && pea2->getX() < zfacs[i]->zombies[j]->current_x)
//						{
//							if (pea2->getY() == zfacs[i]->zombies[j]->current_y)
//							{
//								// Here decide what will happen to the Zombie
//								pea_exists2[1] = false;
//								pea2->setY(pea2->getY() + 10000);
//							}
//						}
//					}
//				}
//				pea2->covered_distance = pea2->getX() - pea2->first_x;
//			}
//			fire_timer.restart();
//		}
//		if (pea_exists[1] && pea2->covered_distance >= 1246)
//		{
//			delete pea2;
//			fired[1] = false;
//			pea_exists[1] = false;
//			pea2->covered_distance = 0;
//		}
//		if (pea_exists[0] && pea1->covered_distance >= 1246)
//		{
//			delete pea1;
//			pea_exists[0] = false;
//			fired[0] = false;
//			pea1->covered_distance = 0;
//		}
//		
//	}
//	void fire(RenderWindow& window)
//	{
//		if (!pea_exists[0])
//		{
//			if (made[0])
//			{
//				if (counter[0] > 0)
//				{
//					pea1 = new Pea(fire_rate, getX() + 30, getY());
//					pea_exists[0] = true;
//					pea_exists2[0] = true;
//					fired[0] = true;
//					counter[0] = 0;
//				}
//			}
//			else
//			{
//				if (counter[0] > 70)
//				{
//					pea1 = new Pea(fire_rate, getX() + 30, getY());
//					pea_exists[0] = true;
//					pea_exists2[0] = true;
//					fired[0] = true;
//					made[0] = true;
//					counter[0] = 0;
//				}
//			}
//			counter[0]++;
//		}
//		else
//		{
//			pea1->update(window, pea_exists2[0]);
//		}
//		if (!pea_exists[1])
//		{
//			if (made[1])
//			{
//				if (counter[1] > 0)
//				{
//					pea2 = new Pea(fire_rate, getX() + 90, getY());
//					pea_exists[1] = true;
//					pea_exists2[1] = true;
//					fired[1] = true;
//					counter[1] = 0;
//				}
//			}
//			else
//			{
//				if (counter[1] > 70)
//				{
//					pea2 = new Pea(fire_rate, getX() + 90, getY());
//					pea_exists[1] = true;
//					pea_exists2[1] = true;
//					fired[1] = true;
//					counter[1] = 0;
//					made[1] = true;
//				}
//			}
//			counter[1]++;
//		}
//	    else
//		{
//			pea2->update(window, pea_exists2[1]);
//		}
//	}
//	void Start_Moving(RenderWindow& window, patch grid[][9])
//	{
//
//	}
//	void setCoordinates(int* cor, bool alpha = false)
//	{
//		setX(cor[0]);
//		setY(cor[1]);
//	}
//	Sprite get_Sprite()
//	{
//		return repeater;
//	}
//	void attack()
//	{
//		cout << "PeaShooter will attack" << endl;
//	}
//	void disappear()
//	{
//		cout << "Pea Sooter will disappear" << endl;
//	}
//};
//
//class Wallnut : public Plant
//{
//	string images[18];
//	Sprite wallnut;
//	int health;
//	bool up;
//	bool down;
//	int image_no;
//	int image_no_2;
//	Clock timer;
//	int counter = 0;
//	bool set = true;
//	int angle;
//public:
//	Wallnut()
//	{
//		image_no = 0;
//		image_no_2 = 0;
//		up = false;
//		down = false;
//		Image wallnut_i;
//		wallnut_i.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/wall1.png");
//		Texture wallnut_t;
//		wallnut_t.loadFromImage(wallnut_i);
//		wallnut.setTexture(wallnut_t);
//		angle = 0;
//		images[0] = "C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/wall1.png";
//	}
//	void draw_on(RenderWindow& window)
//	{
//		if (exists)
//		{
//			Image wallnut_i;
//			wallnut_i.loadFromFile(images[image_no]);
//			Texture wallnut_t;
//			wallnut_t.loadFromImage(wallnut_i);
//			wallnut.setOrigin(wallnut.getLocalBounds().width / 2, wallnut.getLocalBounds().height / 2);
//			wallnut.setTexture(wallnut_t);
//			wallnut.setPosition(getX(), getY());
//			window.draw(wallnut);
//		}
//		else
//			wallnut.setPosition(10000, 10000);
//		
//	}
//	Sprite get_Sprite()
//	{
//		return wallnut;
//	}
//	void attack()
//	{
//		cout << "PeaShooter will attack" << endl;
//	}
//	void disappear()
//	{
//		cout << "Pea Sooter will disappear" << endl;
//	}
//	void update(RenderWindow& window, Zombie_Factory** zfacs, int types_of_zombies, patch grid[][9], int& score) {}
//	void Start_Moving(RenderWindow& window, patch grid[][9])
//	{
//		if (getBool())
//		{
//			setX(getX() + 2);
//			
//			/*int distance_to_upper = abs(getY() - 99);
//			int distance_to_lower = abs(getY() - 595);
//			
//			if (getY()<99)
//			{
//				down = true;
//				up = false;
//			}
//			else if (getY() >= 595)
//			{
//				up = true;
//				down = false;
//			}
//			if (!down && !up)
//			{
//				if (distance_to_upper < distance_to_lower)
//				{
//					setY(getY() - 3);
//					down = false;
//					up = true;
//				}
//				if (distance_to_upper >= distance_to_lower)
//				{
//					setY(getY() + 3);
//					down = true;
//					up = false;
//				}
//			}
//			else if(down)
//				setY(getY() + 3);
//			else if(up)
//				setY(getY() - 3);*/
//			wallnut.setRotation(angle+=20);
//		}
//	}
//	void setCoordinates(int* cor, bool alpha = false)
//	{
//		setX(cor[0]);
//		setY(cor[1]);
//		setBool(alpha);
//	}
//	Sprite getSprite()
//	{
//		return wallnut;
//	}
//};
//
//class SnowPea : public Plant
//{
//	Pea* spea;
//	Sprite snowpea;
//	int health;
//	int fire_rate;
//	bool spea_exists;
//	Clock fire_timer;
//	bool spea_exists2;
//	int counter;
//	bool fired;
//	bool made = false;
//public:
//	SnowPea()
//	{
//		Image snowpea_i;
//		snowpea_i.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/snow.png");
//		Texture snowpea_t;
//		snowpea_t.loadFromImage(snowpea_i);
//		snowpea.setTexture(snowpea_t);
//		spea_exists = false;
//		spea_exists2 = false;
//		fire_rate = 5;
//		counter = 0;
//		fired = false;
//	}
//	void draw_on(RenderWindow& window)
//	{
//		if (exists)
//		{
//			Image snowpea_i;
//			snowpea_i.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/snow.png");
//			Texture snowpea_t;
//			snowpea_t.loadFromImage(snowpea_i);
//			snowpea.setTexture(snowpea_t);
//			snowpea.setPosition(getX(), getY());
//			window.draw(snowpea);
//		}
//		else
//			snowpea.setPosition(10000, 10000);
//	}
//	void update(RenderWindow& window, Zombie_Factory** zfacs, int types_of_zombies, patch grid[][9], int& score)
//	{
//		Time elapsed = fire_timer.getElapsedTime();
//		if (elapsed.asSeconds() > 0.005)
//		{
//			fire(window);
//			if (fired)
//			{
//				for (int i = 0; i < types_of_zombies; i++)
//				{
//					for (int j = 0; j < zfacs[i]->numZombies; j++)
//					{
//						if (spea->getX() > zfacs[i]->zombies[j]->current_x - 40 && spea->getX() < zfacs[i]->zombies[j]->current_x)
//						{
//							if (spea->getY() == zfacs[i]->zombies[j]->current_y)
//							{
//								// Here decide what will happen to the Zombie
//								spea_exists2 = false;
//								spea->setY(spea->getY() + 10000);
//							}
//						}
//					}
//				}
//				spea->covered_distance = spea->getX() - spea->first_x;
//			}
//			fire_timer.restart();
//		}
//		if (spea_exists && spea->covered_distance >= 1246)
//		{
//			delete spea;
//			spea_exists = false;
//			fired = false;
//			spea->covered_distance = 0;
//		}
//	}
//	void fire(RenderWindow& window)
//	{
//		if (!spea_exists)
//		{
//			if (made)
//			{
//				if (counter > 0)
//				{
//					spea = new Pea(fire_rate, getX(), getY(), "Spea");
//					spea_exists = true;
//					spea_exists2 = true;
//					fired = true;
//					counter = 0;
//				}
//			}
//			else
//			{
//				if (counter > 70)
//				{
//					spea = new Pea(fire_rate, getX(), getY(), "Spea");
//					spea_exists = true;
//					spea_exists2 = true;
//					fired = true;
//					made = true;
//					counter = 0;
//				}
//			}
//			counter++;
//		}
//		else
//		{
//			spea->update(window, "Spea", spea_exists2);
//		}
//	}
//	void Start_Moving(RenderWindow& window, patch grid[][9])
//	{}
//
//	void setCoordinates(int* cor, bool alpha = false)
//	{
//		setX(cor[0]);
//		setY(cor[1]);
//	}
//	Sprite get_Sprite()
//	{
//		return snowpea;
//	}
//	void attack()
//	{
//		cout << "PeaShooter will attack" << endl;
//	}
//	void disappear()
//	{
//		cout << "Pea Sooter will disappear" << endl;
//	}
//};
//
//class Cherry_Bomb : public Plant
//{
//	Sprite cherry_bomb;
//public:
//	Cherry_Bomb()
//	{
//		Image cherry_bomb_i;
//		cherry_bomb_i.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/cherry.png");
//		Texture cherry_bomb_t;
//		cherry_bomb_t.loadFromImage(cherry_bomb_i);
//		cherry_bomb.setTexture(cherry_bomb_t);
//	}
//	void draw_on(RenderWindow& window) override
//	{
//		if (exists)
//		{
//			Image cherry_bomb_i;
//			cherry_bomb_i.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/cherry.png");
//			Texture cherry_bomb_t;
//			cherry_bomb_t.loadFromImage(cherry_bomb_i);
//			cherry_bomb.setTexture(cherry_bomb_t);
//			cherry_bomb.setPosition(getX(), getY());
//			window.draw(cherry_bomb);
//		}
//		else
//			cherry_bomb.setPosition(10000, 10000);
//	}
//	void setCoordinates(int* cor, bool alpha = false)
//	{
//		setX(cor[0]);
//		setY(cor[1]);
//	}
//	void Start_Moving(RenderWindow& window, patch grid[][9])
//	{
//
//	}
//	Sprite get_Sprite() override
//	{
//		return cherry_bomb;
//	}
//	void attack() override
//	{
//		cout << "PeaShooter will attack" << endl;
//	}
//	void disappear() override
//	{
//		cout << "Pea Sooter will disappear" << endl;
//	}
//	void update(RenderWindow& window, Zombie_Factory** zfacs, int types_of_zombies, patch grid[][9], int& score)
//	{}
//};

#pragma once
#include "Plant.h"
#include <iostream>
#include "Pea.h"
#include "Static Sun.h"
using namespace std;
using namespace sf;

class PeaShooter : public Plant
{
	Pea* pea;
	Texture peashooter_texture[77];
	Sprite peashooter;
	int fire_rate;
	int damage;
	Clock fire_timer;
	bool pea_exists;
	bool pea_exists2;
	bool made;
	int counter;
	bool fired = false;

public:
	PeaShooter()
	{
		fire_rate = 5;
		health = 100;

		string path = "C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/Plants/Peashooter/peashooter- (";
		for (int i = 0; i < 77; i++) {
			string pathe = path + to_string(i + 1) + ").gif";
			peashooter_texture[i].loadFromFile(pathe);
		}


		pea_exists = false;
		fired = false;
		counter = 0;
		pea_exists = false;
		pea_exists2 = false;
		made = false;
	}
	void draw_on(RenderWindow& window)
	{

		peashooter.setPosition(getX(), getY());

		if (texture_num >= 77)
			texture_num = 0;
		peashooter.setTexture(peashooter_texture[texture_num++]);

		peashooter.setOrigin(0, peashooter.getLocalBounds().height / 4);

		window.draw(peashooter);
	}
	//void  update(RenderWindow& window, Zombie_Factory** zfacs, int types_of_zombies, patch grid[][9],int& score)
	//{
	//	Time elapsed = fire_timer.getElapsedTime();
	//	if (elapsed.asSeconds() > 0.005)
	//	{
	//		fire(window);
	//		for (int i = 0; i < types_of_zombies; i++)
	//		{
	//			for (int j = 0; j < zfacs[i]->numZombies; j++)
	//			{
	//				if (pea->getX() > zfacs[i]->zombies[j]->current_x - 40)
	//				{
	//					if (pea->getY() == zfacs[i]->zombies[j]->current_y)
	//					{
	//						// Here decide what will happen to the Zombie
	//						zfacs[i]->zombies[j]->health -= 20;
	//						delete pea;
	//						pea_exists = false;
	//					}
	//				}
	//			}
	//		}
	//		fire_timer.restart();
	//	}
	//	if (pea_exists && pea->getX() >= 1246)
	//	{
	//		delete pea;
	//		pea_exists = false;
	//	}
	//}
	void update(RenderWindow& window, Zombie_Factory** zfacs, int types_of_zombies, patch grid[][9], int& score)
	{
		Time elapsed = fire_timer.getElapsedTime();
		if (elapsed.asSeconds() > 0.005)
		{
			fire(window);
			if (fired)
			{
				for (int i = 0; i < types_of_zombies; i++)
				{
					for (int j = 0; j < zfacs[i]->numZombies; j++)
					{
						if (pea->getX() > zfacs[i]->zombies[j]->current_x - 40 && pea->getX() < zfacs[i]->zombies[j]->current_x)
						{
							if (pea->getY() == zfacs[i]->zombies[j]->current_y)
							{
								// Here decide what will happen to the Zombie
								zfacs[i]->zombies[j]->health -= 20;
								pea_exists2 = false;
								pea->setY(pea->getY() + 1000);
							}
						}
					}
				}
				pea->covered_distance = pea->getX() - pea->first_x;
			}
			fire_timer.restart();
		}
		if (pea_exists && pea->covered_distance >= 1246)
		{
			delete pea;
			pea_exists = false;
			fired = false;
			pea->covered_distance = 0;
		}


	}

	void attack()
	{
		cout << "PeaShooter will attack" << endl;
	}
	void disappear()
	{
		cout << "Pea Sooter will disappear" << endl;
	}
	void fire(RenderWindow& window)
	{
		if (!pea_exists)
		{
			if (made)
			{
				if (counter > 0)
				{
					pea = new Pea(fire_rate, getX(), getY());
					pea_exists = true;
					pea_exists2 = true;
					counter = 0;
					fired = true;
				}
			}
			else
				if (counter > 70)
				{
					pea = new Pea(fire_rate, getX(), getY());
					pea_exists = true;
					pea_exists2 = true;
					counter = 0;
					fired = true;
					made = true;

				}

			counter++;
		}
		else
		{
			pea->update(window, pea_exists2);
		}
	}
	Sprite get_Sprite()
	{
		return peashooter;
	}
	Pea* get_Bullet()
	{
		return pea;
	}
	~PeaShooter()
	{
		cout << "Destructed" << endl;
	}
	void setCoordinates(int* cor, bool alpha = false)
	{
		setX(cor[0]);
		setY(cor[1]);
	}
	void Start_Moving(RenderWindow& window, patch grid[][9])
	{

	}
};
class Sunflower : public Plant
{
	Static_Sun* sun;
	Texture sunflower_texture[50];
	Sprite sunflower;
	int spwan_rate;
	bool sun_exists;
	Clock sun_timer;
	Clock de_spwan;
public:
	Sunflower()
	{
		health = 100;
		string path = "C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/Plants/Sunflower/sunflower- (";

		for (int i = 0; i < 50; i++)
		{
			string pathe = path + to_string(i + 1) + ").png";
			sunflower_texture[i].loadFromFile(pathe);
		}

		sun_exists = false;
	}
	void draw_on(RenderWindow& window)
	{
		if (texture_num >= 50)
			texture_num = 0;
		sunflower.setScale(1.4, 1.7);
		sunflower.setOrigin(0, sunflower.getLocalBounds().height / 2);
		sunflower.setTexture(sunflower_texture[texture_num++]);

		sunflower.setPosition(getX(), getY());
		window.draw(sunflower);
	}
	void update(RenderWindow& window, Zombie_Factory** zfacs, int types_of_zombies, patch grid[][9], int& score)
	{
		Time despawn_sun = de_spwan.getElapsedTime();
		if (sun_exists)
		{
			if (sun->isTouched(Mouse::getPosition().x, Mouse::getPosition().y, sun->getSprite()) && Mouse::isButtonPressed(Mouse::Left)) 
			{
				sun_exists = false;
				Score(score);
			}
			if (despawn_sun.asSeconds() > 5)  // If not touched for 5 seconds, set sun_exists to false
			{
				sun_exists = false;
				de_spwan.restart();
				sun_timer.restart();
			}
			if (sun_exists)
				sun->spawn_Sun(window);
		}

		Time elapsed_time = sun_timer.getElapsedTime();
		if (elapsed_time.asSeconds() > 10 && !sun_exists)
		{
			sun = new Static_Sun(window, getX() + 100, getY() + 70);
			sun_exists = true;
			sun_timer.restart();
			de_spwan.restart();
		}
	}
	Sprite get_Sprite()
	{
		return sunflower;
	}
	void attack()
	{
		cout << "PeaShooter will attack" << endl;
	}
	void disappear()
	{
		cout << "Pea Sooter will disappear" << endl;
	}
	void setCoordinates(int* cor, bool alpha = false)
	{
		setX(cor[0]);
		setY(cor[1]);
	}
	void Start_Moving(RenderWindow& window, patch grid[][9])
	{
	}
};

class Repeater : public Plant
{
	Pea* pea1;
	Pea* pea2;
	Sprite repeater;
	Texture repeater_texture[49];
	int fire_rate;
	bool pea_exists[2];
	Clock fire_timer;

	bool pea_exists2[2];
	bool fired[2];
	int counter[2];
	bool made[2];
public:
	Repeater()
	{
		fire_rate = 5;
		string path = "C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/Plants/Repeater/repeater- (";

		for (int i = 0; i < 49; i++)
		{
			string pathe = path + to_string(i + 1) + ").png";
			repeater_texture[i].loadFromFile(pathe);
		}


		pea_exists[0] = false;
		pea_exists[1] = false;

		pea_exists2[0] = false;
		pea_exists2[1] = false;
		fired[0] = false;
		fired[1] = false;
		counter[0] = 0;
		counter[1] = 0;
		made[0] = false;
		made[1] = false;
	}
	void draw_on(RenderWindow& window)
	{
		if (texture_num >= 49)
			texture_num = 0;

		repeater.setTexture(repeater_texture[texture_num++]);
		repeater.setScale(1.4, 1.7);

		repeater.setOrigin(0, repeater.getLocalBounds().height / 3);
		repeater.setPosition(getX(), getY());
		window.draw(repeater);
	}
	void update(RenderWindow& window, Zombie_Factory** zfacs, int types_of_zombies, patch grid[][9], int& score)
	{
		Time elapsed = fire_timer.getElapsedTime();
		if (elapsed.asSeconds() > 0.005)
		{
			fire(window);
			if (fired[0])
			{
				for (int i = 0; i < types_of_zombies; i++)
				{
					for (int j = 0; j < zfacs[i]->numZombies; j++)
					{
						if (pea1->getX() > zfacs[i]->zombies[j]->current_x - 40 && pea1->getX() < zfacs[i]->zombies[j]->current_x)
						{
							if (pea1->getY() == zfacs[i]->zombies[j]->current_y)
							{
								// Here decide what will happen to the Zombie
								zfacs[i]->zombies[j]->health -= 20;
								pea_exists2[0] = false;

								pea1->setY(pea1->getY() + 1000);

							}
						}
					}
				}
				pea1->covered_distance = pea1->getX() - pea1->first_x;
			}
			if (fired[1])
			{
				for (int i = 0; i < types_of_zombies; i++)
				{
					for (int j = 0; j < zfacs[i]->numZombies; j++)
					{
						if (pea2->getX() > zfacs[i]->zombies[j]->current_x - 40 && pea2->getX() < zfacs[i]->zombies[j]->current_x)
						{
							if (pea2->getY() == zfacs[i]->zombies[j]->current_y)
							{
								// Here decide what will happen to the Zombie
								zfacs[i]->zombies[j]->health -= 20;
								pea_exists2[1] = false;
								pea2->setY(pea2->getY() + 1000);
							}
						}
					}
				}
				pea2->covered_distance = pea2->getX() - pea2->first_x;
			}
			fire_timer.restart();
		}
		if (pea_exists[1] && pea2->covered_distance >= 1246)
		{
			delete pea2;
			fired[1] = false;
			pea_exists[1] = false;
			pea2->covered_distance = 0;
		}
		if (pea_exists[0] && pea1->covered_distance >= 1246)
		{
			delete pea1;
			pea_exists[0] = false;
			fired[0] = false;
			pea1->covered_distance = 0;
		}

	}
	void fire(RenderWindow& window)
	{
		if (!pea_exists[0])
		{
			if (made[0])
			{
				if (counter[0] > 0)
				{
					pea1 = new Pea(fire_rate, getX() + 30, getY());
					pea_exists[0] = true;
					pea_exists2[0] = true;
					fired[0] = true;
					counter[0] = 0;
				}
			}
			else
			{
				if (counter[0] > 70)
				{
					pea1 = new Pea(fire_rate, getX() + 30, getY());
					pea_exists[0] = true;
					pea_exists2[0] = true;
					fired[0] = true;
					made[0] = true;
					counter[0] = 0;
				}
			}
			counter[0]++;
		}
		else
		{
			pea1->update(window, pea_exists2[0]);
		}
		if (!pea_exists[1])
		{
			if (made[1])
			{
				if (counter[1] > 0)
				{
					pea2 = new Pea(fire_rate, getX() + 90, getY());
					pea_exists[1] = true;
					pea_exists2[1] = true;
					fired[1] = true;
					counter[1] = 0;
				}
			}
			else
			{
				if (counter[1] > 70)
				{
					pea2 = new Pea(fire_rate, getX() + 90, getY());
					pea_exists[1] = true;
					pea_exists2[1] = true;
					fired[1] = true;
					counter[1] = 0;
					made[1] = true;
				}
			}
			counter[1]++;
		}
		else
		{
			pea2->update(window, pea_exists2[1]);
		}
	}
	Sprite get_Sprite()
	{
		return repeater;
	}
	void attack()
	{
		cout << "PeaShooter will attack" << endl;
	}
	void disappear()
	{
		cout << "Pea Sooter will disappear" << endl;
	}
	void Start_Moving(RenderWindow& window, patch grid[][9])
	{

	}
	void setCoordinates(int* cor, bool alpha = false)
	{
		setX(cor[0]);
		setY(cor[1]);
	}
};

class Wallnut : public Plant
{
	Texture wallnut_texture[44];
	Sprite wallnut;
	bool up;
	bool down;
	int image_no;
	int image_no_2;
	Clock timer;
	int counter = 0;
	int angle;

public:
	Wallnut()
	{
		image_no = 0;
		image_no_2 = 0;
		up = false;
		down = false;

		string path = "C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/Plants/wallnut/wallnut- (";
		for (int i = 0; i < 44; i++) {
			string pathe = path + to_string(i + 1) + ").png";
			wallnut_texture[i].loadFromFile(pathe);
		}
		angle = 0;
		texture_num = 0;
		health = 300;

	}
	void draw_on(RenderWindow& window)
	{

		if (texture_num >= 44)
			texture_num = 0;

		wallnut.setTexture(wallnut_texture[texture_num++]);
		wallnut.setOrigin(wallnut.getLocalBounds().width / 2, wallnut.getLocalBounds().height / 2);

		wallnut.setPosition(getX(), getY());
		window.draw(wallnut);

	}
	Sprite get_Sprite()
	{
		return wallnut;
	}
	void attack()
	{
		cout << "PeaShooter will attack" << endl;
	}
	void disappear()
	{
		cout << "Pea Sooter will disappear" << endl;
	}
	void update(RenderWindow& window, Zombie_Factory** zfacs, int types_of_zombies, patch grid[][9], int& score)
	{
		for (int i = 0; i < types_of_zombies; i++)
		{
			for (int j = 0; j < zfacs[i]->numZombies; j++)
			{
				if (getX() > zfacs[i]->zombies[j]->current_x - 40 && getX() < zfacs[i]->zombies[j]->current_x)
				{
					if (getY() == zfacs[i]->zombies[j]->current_y)
					{
						// Here decide what will happen to the Zombie
						zfacs[i]->zombies[j]->health -= 1000;
					}
				}
			}
		}

	}
	void Start_Moving(RenderWindow& window, patch grid[][9])
	{
		if (getBool())
		{
			setX(getX() + 2);

			/*int distance_to_upper = abs(getY() - 99);
			int distance_to_lower = abs(getY() - 595);

			if (getY()<99)
			{
				down = true;
				up = false;
			}
			else if (getY() >= 595)
			{
				up = true;
				down = false;
			}
			if (!down && !up)
			{
				if (distance_to_upper < distance_to_lower)
				{
					setY(getY() - 3);
					down = false;
					up = true;
				}
				if (distance_to_upper >= distance_to_lower)
				{
					setY(getY() + 3);
					down = true;
					up = false;
				}
			}
			else if(down)
				setY(getY() + 3);
			else if(up)
				setY(getY() - 3);*/
			wallnut.setRotation(angle += 20);
		}
	}
	void setCoordinates(int* cor, bool alpha = true)
	{
		setX(cor[0]);
		setY(cor[1]);
		setBool(alpha);
	}
	Sprite getSprite()
	{
		return wallnut;
	}
};

class SnowPea : public Plant
{
public:
	Pea* spea;
	Texture snowpea_texture[25];
	Sprite snowpea;
	int fire_rate;
	bool spea_exists;
	Clock fire_timer;

	bool spea_exists2;
	int counter;
	bool fired;
	bool made = false;
public:
	SnowPea()
	{
		string path = "C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/Plants/snowpea/snowpea- (";

		for (int i = 0; i < 25; i++)
		{
			string pathe = path + to_string(i + 1) + ").png";
			snowpea_texture[i].loadFromFile(pathe);
		}
		spea_exists = false;
		fire_rate = 5;
	}
	void draw_on(RenderWindow& window)
	{
		if (texture_num >= 25)
			texture_num = 0;

		snowpea.setTexture(snowpea_texture[texture_num++]);

		snowpea.setPosition(getX(), getY());
		window.draw(snowpea);
	}
	void update(RenderWindow& window, Zombie_Factory** zfacs, int types_of_zombies, patch grid[][9], int& score)
	{
		Time elapsed = fire_timer.getElapsedTime();
		if (elapsed.asSeconds() > 0.005)
		{
			fire(window);
			if (fired)
			{
				for (int i = 0; i < types_of_zombies; i++)
				{
					for (int j = 0; j < zfacs[i]->numZombies; j++)
					{
						if (spea->getX() > zfacs[i]->zombies[j]->current_x - 40 && spea->getX() < zfacs[i]->zombies[j]->current_x)
						{
							if (spea->getY() == zfacs[i]->zombies[j]->current_y)
							{
								// Here decide what will happen to the Zombie
								zfacs[i]->zombies[j]->health -= 20;
								zfacs[i]->zombies[j]->speed -= 0.005;

								spea_exists2 = false;
								spea->setY(spea->getY() + 1000);
							}
						}
					}
				}
				spea->covered_distance = spea->getX() - spea->first_x;
			}
			fire_timer.restart();
		}
		if (spea_exists && spea->covered_distance >= 1246)
		{
			delete spea;
			spea_exists = false;
			fired = false;
			spea->covered_distance = 0;
		}
	}
	void fire(RenderWindow& window)
	{
		if (!spea_exists)
		{
			if (made)
			{
				if (counter > 0)
				{
					spea = new Pea(fire_rate, getX(), getY(), "Spea");
					spea_exists = true;
					spea_exists2 = true;
					fired = true;
					counter = 0;
				}
			}
			else
			{
				if (counter > 70)
				{
					spea = new Pea(fire_rate, getX(), getY(), "Spea");
					spea_exists = true;
					spea_exists2 = true;
					fired = true;
					made = true;
					counter = 0;
				}
			}
			counter++;
		}
		else
		{
			spea->update(window, "Spea", spea_exists2);
		}
	}
	Sprite get_Sprite()
	{
		return snowpea;
	}
	void attack()
	{
		cout << "PeaShooter will attack" << endl;
	}
	void disappear()
	{
		cout << "Pea Sooter will disappear" << endl;
	}
	void Start_Moving(RenderWindow& window, patch grid[][9])
	{}

	void setCoordinates(int* cor, bool alpha = false)
	{
		setX(cor[0]);
		setY(cor[1]);
	}
};

class CherryBomb : public Plant
{
	sf::Texture cherryBombTexture;
	sf::Sprite cherryBombSprite;
	bool exploded;
	sf::Clock explosionTimer;

public:
	CherryBomb()
	{

		cherryBombTexture.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/Plants/cherry.png");
		cherryBombSprite.setTexture(cherryBombTexture);
		exploded = false;
	}

	void draw_on(sf::RenderWindow& window) override
	{
		if (!exploded)
		{
			cherryBombSprite.setPosition(getX(), getY());
			window.draw(cherryBombSprite);
		}
	}

	void update(sf::RenderWindow& window, Zombie_Factory** zfacs, int types_of_zombies, patch grid[][9], int& score) override
	{
		if (!exploded)
		{
			if (explosionTimer.getElapsedTime().asSeconds() >= 2)
			{
				explode(zfacs, types_of_zombies, grid);
			}
		}
	}

	sf::Sprite get_Sprite() override
	{
		return cherryBombSprite;
	}

	void attack() override
	{
		std::cout << "CherryBomb will attack" << std::endl;
	}

	void disappear() override
	{
		std::cout << "CherryBomb will disappear" << std::endl;
	}

	void setCoordinates(int* cor, bool alpha = false)
	{
		setX(cor[0]);
		setY(cor[1]);
	}
	void Start_Moving(RenderWindow& window, patch grid[][9])
	{

	}

	void explode(Zombie_Factory** zfacs, int types_of_zombies, patch grid[][9])
	{
		exploded = true;
		// Check for zombies in blast radius and decrease their health
		for (int i = 0; i < types_of_zombies; ++i)
		{
			for (int j = 0; j < zfacs[i]->numZombies; ++j)
			{
				int zombieX = zfacs[i]->zombies[j]->current_x;
				int zombieY = zfacs[i]->zombies[j]->current_y;
				int distance_x = abs(zombieX - getX());
				int distance_y = abs(zombieY - getY());
				int diff_x = 102 * 2;
				int diff_y = 124 * 1.5;


				if (distance_x <= diff_x && distance_y <= diff_y)
				{
					// Zombie is in blast radius, decrease its health
					zfacs[i]->zombies[j]->health -= 500; // Adjust the damage as needed
				}
			}
		}

		int x_y[2];
		x_y[0] = getX();
		x_y[1] = getY();
		can_be_placed(grid, x_y, 1);
	}
};