Plants vs. Zombies Clone (C++, SFML)
Object-Oriented Game Development Project

Designed and implemented a 2D tower defense game using OOP principles (inheritance, polymorphism, encapsulation) to model 15+ entity types (plants, zombies, projectiles).

Key Features:

Inheritance Hierarchy: Created base Entity class with derived classes (PeaShooter, Sunflower, Zombie) to streamline behavior overrides (e.g., attack(), move()).

Polymorphism: Used virtual functions for dynamic rendering and collision detection, enabling extensible game objects.

Resource Management: Encapsulated game state (sun points, plant cooldowns) within a GameManager class to prevent global variable misuse.

STL Containers: Leveraged std::vector for entity storage and std::queue for wave spawning logic.

Optimizations: Achieved 60+ FPS by pooling reusable objects (projectiles) to minimize heap allocations.

Tools: SFML (graphics/audio), Git (version control).
