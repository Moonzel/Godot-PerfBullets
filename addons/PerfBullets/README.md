# Godot PerfBullets
![PerfBulletsLogo - Copy](https://github.com/Moonzel/Godot-PerfBullets/assets/96361809/e3c2392a-09f8-4cf9-b98b-f213b233ae62)

## Spawn thousands of bullets or particles on screen in an extremely performant way!

<p align="center">
  <img src="https://github.com/Moonzel/Public_Gifs_For_Projects_Moonzel/blob/main/HomingDemo.gif" width="480" />
  <img src="https://github.com/Moonzel/Public_Gifs_For_Projects_Moonzel/blob/main/SpiralDemo.gif" width="480" />
  <img src="https://github.com/Moonzel/Public_Gifs_For_Projects_Moonzel/blob/main/StressDemo.gif" width="480" />
</p>

This plugin is for **GDExtension** and works with Godot 4.1. Only with Mobile or Forward+ renderers.<br>

The version included is pre-built for Windows

## Main Features

- Spawn performant bullets, written in C++ for max performance 
- Animate bullets using a sprite sheet, while keeping the benefits of a multimesh
- Use custom collision shapes with a custom mask
- Select process mode or physics process mode to move the bullets
- Create a barrier for the bullets so they despawn at a certain distance using BulletBorder Class
- Set the bullets to home to a certain node
- Use the PatternManager Class to create patterns of multiple Spawners easily
- Make multiple arrays of bullets to design more complex patterns

### Basic Setup

### The first six steps are *crucial* for the Spawner to work

1. Make sure the `PerfBullets` plugin is activated in Project Settings.
2. Add a base scene node as a Node2D (or any other node deriving from that class).
3. Add a Spawner node as a child.
4. Create a BulletType resource in the `Bullet Type` property.
5. Set the shape of that BulletType resource (for collision).
6. Set the texture of the node in the MultiMeshInstance2D section of the node (or the sprite sheet if animating).
#### The rest of the steps are optional but recommended to make full use of the plugin.
6. Add a BulletBorder node as the child of the main node.
7. Create two Noed2Ds as children of that node.
8. Select one of those nodes as the `TopLeft` property and one as the `BottomRight` property (this creates the border).
9. Add a PatternManager node
10. For **EVERY** Spawner node in the scene, add a PatternSpawnerData resource.
11. Set the ID of the Spawner, the time till it activates, and the mode of the Timer.
12. If using PatternManager, change the Mode of the Spawner to `PATTERNMANAGER`.
13. Select the Spawner and go to the Signals tab
14. Add the `bullet_hit` signal to the node that will handle what happens to the bullet.
	- There is the option to add multiple signals to the same function.
 	- When going to add the signal to the node that recieves the signal, press the button that says `pick`.
	- Then press the function you wish to add it to, allowing for multiple Spawners to use the same signal.


### Here is what is supposed to look like:
<img src="https://github.com/Moonzel/Public_Gifs_For_Projects_Moonzel/blob/main/BasicDemoUpdated.gif" />

## Examples
In the repository, there is a folder named `examples` that holds a few examples you can build off of to make your games:

 - `stress_test`: This example shows the performance of the plugin by spawning many bullets in a spinning pattern.
 - `aimed_at_player`: This example shows how the Spawner can start in the direction of the player, using an offset to have the shot pointed directly at the player.
 - `basic_setup`: This example shows the most basic implementation of the Spawner, use this as a basis to start new patterns.
 - `basic_setup_with_PatternManager`: The same as the previous example but with the addition of PatternManager.
 - `node_hierarchy`: This example shows how Spawners will work no matter who they are a child of, and can even remain stationary with a moving parent (see moveWithParent).

## Full Documentation

**Along with the methods and properties stated, each property also has a setter and getter function in this format:**
 `set_propertyname()`, `get_propertyname()` (with underscores in-between spaces)

### @ Spawner ![Spawner](https://github.com/Moonzel/Godot-PerfBullets/assets/96361809/ae8e9811-520f-4e99-a0cc-1b5c2e6c2598)


#### The main class of the plugin. This is the base class that manages how bullets are spawned and how they move every frame. Here you can control almost every attribute of how the bullets function including spin, homing, animation, gravity, etc. It also contains the option to choose how the node is started, and what process it uses to run.

<details>
<summary>Methods</summary>
<br>
	
- `void _main(float delta)`: The function that is run every frame, either in the `_process` function or the `_physics_process` function, depending on `spawnerMode`. This function is the largest, containing logic for the following, spawning new bullets, autodeleting the node if there are no more active bullets, setting rotation (though not directly, see `startRotation`), updating the spin, moving the bullets, checking for collision, checking if the bullet is out of bounds (BulletBorder), and checking if the bullet has reached its `maxLifetime`. It acts as the main function of the plugin. 
- `void start_node(String nme)`: The function that runs when the node is started, either on runtime (`ONSTART`) or when the PatternManager signals it (`PATTERNMANAGER`). It sets the scale of the mesh, sets the `startRotation`, and resets the multimesh to the correct properties (instance_count, custom_data, visible_instance_count), creates a BulProps resource for each bullet in the pool, sets the shader parameters for animation, and creates a Timer for the node to be able to spawn bullets in correct intervals (`fireRate`). 
- `void spawn_bullet_self(Vector2 dir)`: Spawns a bullet. It takes in direction, set in the `_main` function. It gets the next index that is not inactive, and sets all of the initial properties of the bullet. It also adds a shape to the `BulProps` resource if there is not one on the shape already. Finally, it appends the bullet's index in the main array to another array, so that in the `_main` function, it only iterates over active bullets. 
- `void clear_all()`: Returns every bullet in the Spawner back into the pool. 
- `void free_bullet_to_pool(int idx)`: Takes in the index of the bullet. It sets the bullet to be invisible, restores its proeprties to the defaults, and removes it from the visible bullets array. 
- `int get_next_idx()`: Iterates over bullets in the main `bullets` array until it finds a bullet that is inactive. It then returns the index so it can be used to spawn a bullet in `spawn_bullet_self`. 
- `void calc_vel(BulProps bul, float delta)`: Is run every frame in the `_main` function. Adds `acceleration` to the bullet, and makes sure that the bullet has not reached its `minSpeed` or `maxSpeed` (as set in BulletType).
- `void _add_shape(BulProps)`: Is run every time a bullet is spawned that does not yet contain a CollisonShape. It looks at BulletType's collision shapes and makes a copy of it to be used for the bullet. This is done so RIDs do not get confused. 
- `void animate(BulProps, int num, float delta)`: Every frame, moves the custom data around to adjust what the shader reads, moving the UVs to produce aniamtion based on spritesheets. Checks if there is more to go in the row, and if there is not, move down a column, and if neither, reset to the origional values.
- `void set_bounding_box(Rect2 box)`: Sets the box that the bullets automatically get added back into the pool. 
- `int get_active_bullet()`: For debug purposes. Returns an array with all of the bullets currently on screen and active. Do not use in production as it could be taxing to performance. 
- `BulProps get_bullet_from_index(int index)`: Returns the bullet at the given index. Can be used to get information from a particular bullet, or set information for a bullet manually.

</details>

<details>
<summary>Properties</summary>
<br>

- `bulletType`: The property where the BulletType resource is created. This controls various properties for the bullets (Reference BulletType).
- `bulletsPerRadius`: The number of bullets that will spawn for every radius on the Spawner.
- `columnsInAtlas`: The number of columns in the sprite sheet (used for animation).
- `degreesBetweenRadii`: If multiple radii are created, this will be the offset between them. This can be used to create more complex patterns with multiple directions.
- `fireRadiusDegrees`: How large the radius is in degrees. For example, a value of 90 would spawn bullets, equally spaced, across a 90-degree space.
- `fireRate`: The number of seconds between bullet spawns.
- `gravity`: The amount of gravity added to the velocity of the bullet. Can be positive or negative.
- `homing`: If the bullets should home towards the Node2D in the `trackedNode` property.
- `homingWeight`: The amount of weight the homing has. The larger the number, the faster it will lock on to the tracked nodes's direction.
- `ID`: The number used to activate certain Spawners with PatternManager. 
- `maxSpin`: The maximum amount the Spawner can spin, it either peaks at the value, or restarts and spins the other way (see restartAtSpin).
- `minSpin`: The minimum amount the Spawner can spin, it either peaks at the value, or restarts and spins the other way (see restartAtSpin).
- `moveWithParent`: Whether or not the Spawner moves with the parent node. If `false`, the Spawner will be stationary, if `true`, it will change positions with the parent node. (This will move all of the bullets together since they are not children in the scene).  
- `numberOfRadii`: The number of radii there are. This should usually be set to 1, but many more complex patterns can be made with this. 
- `numberOfShots`: The number of times that the Spawner spawns a full shot, set to -1 to have it shoot indefinitely. 
- `offsetTowardPlayer`: The offset of the radius against the `trackedNode`. It is there so once you select `startTowardPlayer` or `staysTowardPlayer`, you can have control if you want the Spawner to have the middle point at the `trackedNode` or the end. 
- `poolCount`: The number of bullets in the pool. This cannot be changed after instantiation without an error occurring (this is because of how MultiMesh works). The game will crash if there are not enough bullets, so make sure there is enough in the pool. 
- `randomRadius`: If `randomStart` is selected, this controls the radius that the random bullets can be shot. 
- `randomStart`: Takes the number of bullets in `poolCount` and shoots them in random directions. It will be completely random every time. It can be shot at a certain direction with `randomRadius`. 
- `restartAtSpin`: If `spinAcceleration` is not 0, when the spin value reaches `maxSpin` or `minSpin`, the `spinAcceleration` will begin in the opposite direction, creating nice patterns.
- `returnBulletsToPoolAutomatically`: Whether or not the bullets are freed to the pool when collided with. DO NOT use this if planning on using bullet data from the `bullet_hit` signal. 
- `rowsInAtlas`: The number of rows in the sprite sheet (used for animation).
- `spawnerMode`: Can either be PHYSICS or PROCESS. PHYSICS uses the `_physics_process` for all of the calculations, and PROCESS uses the `_process` for all of the calculations.
- `spinAcceleration`: An amount that is added to the spin every frame. It can be negative or positive.
- `spinRate`: The starting amount of spin. Can be modified by `spinAcceleration`.
- `startMode`: Can either be `ONSTART` or `PATTERNMANAGER`. Nothing is run on the node until it is started. `ONSTART` starts the node as soon as it is added to the tree, and `PATTERNMANAGER` starts the node when the Timer in PatternManager is timed out. 
- `startRotation`: The rotation that the Spawner starts with, in degrees. This is an arbitrary number used in calculations, and you SHOULD NOT edit the actual rotation of the Spawner node.
- `startTowardPlayer`: The starting rotation of the Spawner node is set to look at the `targetNode`. This is set automatically, and an offset can be added with `offsetTowardPlayer`.
- `staysTowardPlayer`: The rotation of the Spawner node is constantly changed to look at the `targetNode`. This is set automatically, and an offset can be added with `offsetTowardPlayer`.
- `textureRotation`: The rotation in degrees that is applied to exclusively the texture.
- `trackedNode`: A Node2D that is tracked for the homing functionality. It can be any type of node derived from the Node2D class.

</details>

<details>
<summary>Signals</summary>
<br>

- `bullet_hit`: An impotant signal. Returns three things: the result array, the index of the bullet, and the spawner. This can be used to control various aspects of the bullet when it is hit. If `returnBulletsToPoolAutomatically` is false, it can be done here (`spawner.free_bullet_to_pool(bulletIndex)`). It is also possible to spawn a different scene such as another type of bullet here. There could be a Area2D that when the bullet collides with it, certain properties are changed. (See Basic Setup step 14 for another application of this signal).

</details>

### @ BulletType ![BulletType](https://github.com/Moonzel/Godot-PerfBullets/assets/96361809/711d80b6-13c0-4008-ba4d-847d1cb5edc8)

#### A resource that is used for the Spawner's `Bullet Type` property. This decides certain key attributes of the bullets spawned in that Spawner, and since it is a resource, you can save the resource as a specific type of bullet, and use other Spawners that use the resource. Every bullet in the Spawner shares these properties. Try to not edit these settings after runtime, as many are set once when the Spawner is added to the tree. 

<details>
<summary>Properties</summary>
<br>
	
- `acceleration`: A value that is added to each bullet's speed every frame, increasing it over time, or decreasing it over time. 
- `animationSpeed`: The speed in seconds between switches of the frame. Every time `animationSpeed` time passes, the frame is switched on the bullet unless there is one frame. 
- `collideWithAreas`: If the bullets can collide with physics bodies or not. 
- `collideWithBodies`: If the bullets can collide with area2ds or not. 
- `initialSpeed`: The initial speed that every bullet starts with. 
- `mask`: The collision mask that controls what layers the bullets are checking for. 
- `maxLifetime`: The maximum lifetime the bullets have before automatically being returned to the bullet pool. (`free_to_bullet_pool`).
- `maxSpeed`: The maximum speed that a bullet can go (when using acceleration) before it stops increasing or decreasing (depending on the acceleration's direction) in speed.
- `minSpeed`: The minimum speed that a bullet can go (when using acceleration) before it stops increasing or decreasing (depending on the acceleration's direction) in speed.
- `scale`: The scale of the image used for the bullets. Does not scale the collision shape. 
- `numberOfQueries`: The number of physics queries conducted each frame. It may be better to keep this at 1 for performance reasons, but the option is here if more are needed.

</details>

### @ BulletBorder ![BulletBorder](https://github.com/Moonzel/Godot-PerfBullets/assets/96361809/a3392bf8-b281-4463-b9ce-aa82de0c431d)

#### A class that sets a rectangular border with two Node2Ds. When a bullet passes the border, it adds bullets back into the pool and deactivates them. In the editor, you can place these Node2Ds to designate the rectangle. It is recommended to place them just outside the screen, so the player does not see the bullets despawning.

<details>
<summary>Properties</summary>
<br>

- `topLeft`: A Node2D, whose position is used to determine the top left position of the rectangle representing the BulletBorder. 
- `bottomRight`: A Node2D, whose position is used to determine the bottom right position of the rectangle representing the BulletBorder. 
- `boundaryRect`: The constructed Rect2 using `TopLeft` and `BottomRight`. 

</details>

<details>
<summary>Methods</summary>
<br>

- `void update_boundary_rect()`: Automatically runs once in the `_ready` function of the BulletBorder, but can be run as often as needed. It sets the `boundry_rect` of the Spawner (internally) so the bullets will run `free_bullet_to_pool` when they pass the rect. 

</details>

### @ PatternManager ![PatternManager](https://github.com/Moonzel/Godot-PerfBullets/assets/96361809/3c8d1c62-26f8-4402-a6d3-0e81934fb8c6)

#### This node is set up to be a place where you can control the timings of when each node is fired, usually placed at the same level in the scene as the Spawners. When you add a Spawner to the scene, you can add a corresponding Timer node as a child of the PatternManager. When this Timer times out, it will send a signal with its name (which should also be the EXACT name of the Spawner) and will activate it. You have the option of either using the PatternManager method or instantiating the nodes when you want to use them (`ONSTART`).

<details>
<summary>Properties</summary>
<br>

- `data`: An Array with one PatternSpawnerData per Spawner. It specifies when each Spawner will spawn, based on the time, ID, and timerMode properties of the PatternSpawnerData. 

</details>

<details>
<summary>Methods</summary>
<br>

- `find_spawners(startingNode: Node) -> Array`: Takes in a node to start the search (usually the parent of the PatternManager), and recursively finds every Spawner node under the parent. It the adds it to an array to set up the rest of the PatternManager. 

</details>

<details>
<summary>Signals</summary>
<br>

- `start`: Takes in the name of the node. Activates each spawner once the timer has run out. The name of the Timer MUST be the exact name of the Spawner to work. 

</details>

### @ BulProps ![BulProps](https://github.com/Moonzel/Godot-PerfBullets/assets/96361809/c7f5f0ac-517b-4cdf-8906-8563a0da4867)

#### It is the resource associated with each bullet that is spawned. It is mostly internal within the Spawner class. Can be edited directly, but only by `get_bullet_from_index()`.

<details>
<summary>Properties</summary>
<br>

- `position`: The LOCAL position of the bullet (from its Spawner node).
- `direction`: The Vector2 that describes the direction that the bullet is traveling. 
- `speed`: The amount that is multiplied by the direction to produce the velocity of the bullet.
- `lifetime`: The amount of time the bullet has been active. Is reset every time it is readded to the pool. Is incremented up by delta every frame.
- `animationTime`: The amount of time (in seconds) that has passed between every animation interval (the time between every frame change for animation)
- `shapeRID`: The unique RID associated with the shape that is used to detect collision. Is not attached to any node or PhysicsBody, all of the calculations with collision are done via the Spawner. 

</details>

### @ PatternSpawnerData ![PatternSpawnerData](https://github.com/Moonzel/Godot-PerfBullets/assets/96361809/466f3252-5434-4977-83b4-9bc8ad571b2e)

#### This is a resource that is used by PatternManager to hold data for which Spawners should activate when.

<details>
<summary>Properties</summary>
<br>

- `ID`: The `ID` of the Spawner, so it can be found in the tree.
- `time`: The amount of time till the Spawner activates in seconds.
- `timerMode`: Either Physics or Idle. It determines which mode the timer is run on. 

</details>

### @ PerfBulletsAnimation Shader

#### This is the shader used in the backend to make the animation work with the MultiMeshInstance2D. It is recommended not to change much about this shader, but if extra effects are needed for the bullets, combine them with this shader. This shader is needed for the Spawner to function, otherwise, it will crash. 

<details>
<summary>Properties</summary>
<br>

- `col`: Set at the runtime of the Spawner node based on the `columnsInAtlas` property. There should be no need to ever edit this property manually. 
- `row`: Set at the runtime of the Spawner node based on the `rowsInAtlas` property. There should be no need to ever edit this property manually.
- `custom`: This is a varying vec4 that is set in the vertex shader. It takes the `INSTANCE_CUSTOM` property and applies it to `custom`, so it can be used in the fragment shader. The custom data is in this format (visibility of the bullet (0.0 or 1.0), offsetx (the offset for the x-axis changed to produce animation), offsety (the offset for the y-axis changed to produce animation)).

</details>

## Instructions for Editing the Plugin
### You may come to the point in your project that needs a specific feature that is not included in the base plugin. If this happens, you can edit the plugin yourself.

**If not familiar with C++, use these links to get started:**
- https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/gdextension_cpp_example.html (Godot Documentation)
- https://www.youtube.com/playlist?list=PLhixpuPeRv9aDdsZbhTpsXguYRvMgyVQ- (GDExtennsion Tutorials by moshen zare)

#### Steps for editing the plugin with C++
*Assuming you have the plugin installed in your current project*
1. Download the cpp code for the correct branch (your version) from https://github.com/godotengine/godot-cpp.
2. Paste the `godot-cpp-4.x` folder in the `addons/PerfBullets` folder.
3. Download SCons:
   - Go to Windows Powershell or Terminal.
   - Run `Set-ExecutionPolicy RemoteSigned -scope CurrentUser`.
   - Press "Y" if prompted.
   - Then run `iwr -useb get.scoop.sh | iex`.
   - Finally run `scoop install gcc python scons make mingw`.
5. Rename `godot-cpp-4.x` to `godot-cpp`.
6. Go inside the `godot-cpp` and open the terminal or command line with that location (cd).
7. Run `scons`, and wait for the bindings to install.
8. Open the plugin in a code editor such as Visual Studio.
   - Make sure that all of the paths in the code editor of choice are correct, so it does not give errors
9. Make changes to the plugin.
10. Go inside the `addons/PerfBullets` and open the terminal or command line with that location (cd).
11. Finally run `scons` while Godot is NOT OPEN.
12. It should have successfully updated the C++ aspects of the plugin.

#### Possible Errors

- There could be an issue with SCons not selecting the correct compiler. Double check that there is not another softwre that is auto-setting the compiler to be incorrect.
- There could be a `.gdignore` file in the main folder which would be causing Godot to not be able to access the Classes. There IS supposed to be one in the `/src` folder.
- Check the file placement and the locations in the SConstruct file.
- If it is none of these, refer to the moshen zare videos referenced above. 

## Liscense 

### This plugin is under the MIT License. You may use or change this software in any way. Credit is not required but would be appreciated.

## Support
Please star this repository and share it with other developers who would also benefit from this plugin!
