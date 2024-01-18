extends Area2D

var input: Vector2
@export var power: float
##The id of the spawner used for shooting (If the Spawner has a startmode of Signal)


func _physics_process(delta):
	var velocity = Vector2.ZERO
	input = Vector2(Input.get_axis("ui_left", "ui_right"), Input.get_axis("ui_up", "ui_down")).normalized()
	velocity = input * power
	if input.x == 0:
		velocity.x = 0
	if input.y == 0:
		velocity.y = 0
	position += velocity * delta
	
	#This checks if the spawner is in manual mode, and if it is, it sets the manual start to true. This causes one firing of the pattern.
	if get_node_or_null("PlayerShot") != null: #just because I used this script in multiple examples
		if $PlayerShot.startMode == 2:
			if Input.is_action_just_pressed("ui_accept"):
				$PlayerShot.set_manual_start(true)


func _on_bullet_hit(result, bulletIndex, spawner):
#	spawner.free_bullet_to_pool(bulletIndex) #can be used if returnBulletsToPoolAutomatically is false (see documentation on README)
	print("hit ", result[0]["collider"])

