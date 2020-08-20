# Particle Explosion Project
This project is based on John Purcell's (caveofprogramming.com) Particle Explosion project.
The purpose of this project is to improve my understanding of both OOP and graphics. Additionally, the project will be used to learn GPGPU programming, using CUDA.

Library dependencies of the project are:
 - SDL2

 To do:
 - Clean code
 - Update documentation
 - Modify particle class
    - Remove "rotation axis"
    - Add mass
    - Move update() out of particle. (Movement will depend on all the other "particles" in the space)
 - Modify swarm class
    - Paralellize the class
 - Modify screen class
    - Paralellize the class