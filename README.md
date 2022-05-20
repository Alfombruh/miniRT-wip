/////MUST FINISH//////

- cylinder intersection aswell as other shape(perhaps a triangle)
- fix raytracing
- norminette

/////MINIRT/////

This a simple raytracer. It simply does raycasting a then traces a ray from the intersection of the original ray with an object to the light source (just one light source).
It takes an .rt as a parameter, the .rt file has some parameter that must be written this way:
A 0.2 255,255,255 (A is the idenfiticator of Ambien Light, the first number is the intensity and the second one the color, there's only one of this element)

C 20,20,20, 1,0,0 90 (C is the Camera indenficator, the first numbers are his coordinates, the second one is the camera's vector. This vector has to be normalized and only look in one axis, for example: 1,0,0|0,1,0|0,0,-1)

L -40,50,0 0.6 10,0,255 (L means LightSource, its first parameter is coordinates, the second one the brightnedd and the last one the color, even tho I dont use it)

sp 30,20,20 5.2 10,60,20 (sp stands for Sphere, its parameters are coordinates, diameter and color)

pl 20,20,20 0,1,0 225,225,225 (pl is the Plane, the  first parameter are the coords, the second one the normal vector and the third one its color)

cy 20,20,50 0,1,0 10.6 21.2 150,20,70 (cy is the Cylinder element, it has coords as its first parameter, normal vector as his second one, diameter has his third one, then height and at last the color)


-You can mute a line by adding # at the start of the line.

-You can separate each line by the amount of \n you want and you can also  separate each elements parameter by spaces to make it more readable. It's UP2U


-Q: How many of each element can we use in the .rt?

-A: Its been made to have 1 Camera, 1 LightSource, 1 AmbientLight and as many  of the other ones as you want.


-Q: What are the coords of the cylinder?

-A: In this case the bottom of the cylinder. But you could use it as the middle or top, in this case I used it as the bottom bc I wanted to.


-Q: Wich numbers can we write in each parameter?

-A: Vectors must be normalized and take double values (0.0), coordinates do also take double as a value, colors take R,G,B as integers (0), and the other parameters are all doubles.


-Q: Why does the camera vector only point in one axis???? 

-A: Cause it is a simple raytracer and to create a camera element we need two vectors, the direction and up ones (those two must be perpendicular). The problem here is that the subject only gives us the direction one, so we cannot calculate the up one.


/////SOURCES/////

-My youtube raytracing playlist(https://www.youtube.com/playlist?list=PLw49shePyaZGVJ-hghhdvHKmdQXgWfu6E)

-Someones raytracing gitwiki (https://wiki.nikiv.dev/computer-graphics/ray-tracing)

-RayTracing in one Weekend (https://programmerclick.com/article/8750428968/) This is a series of books bout raytracing

-UC-Davis Academy Raytracing Series(https://www.youtube.com/watch?v=mpTl003EXCY&list=RDCMUCgS7zY8JdEr7v9KEpN19OpQ&index=3) 

-Write a RayTracer Intuitively (https://blog.scottlogic.com/2020/03/10/raytracer-how-to.html)

-THIS (https://www.scratchapixel.com/)

-POV RayTracer (https://www.povray.org/documentation/3.7.0/t2_1.html ||  http://www.povray.org/)

-Nvidia Raytracing Essentials (https://www.youtube.com/watch?v=gBPNO6ruevk&list=PL5B692fm6--sgm8Uiava0IIvUojjFOCSR)

-Some cool slides (http://www.irisa.fr/prive/kadi/Master_Recherche/cours_CTR/RayTracing.pdf)

-Other slides (https://www.doc.ic.ac.uk/~dfg/graphics/graphics2009/GraphicsLecture11.pdf)

-MOAR slides (https://mrl.cs.nyu.edu/~dzorin/rendering/lectures/lecture3/lecture3.pdf)

-RayTracing things (https://www.cl.cam.ac.uk/teaching/1999/AGraphHCI/SMAG/node2.html#eqn:rectray)

-Intersections (https://hugi.scene.org/online/hugi24/coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm)


#THERE ARE WAY MORE BUT THESE ARE THE ONES I SAVED 
