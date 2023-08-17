extends Area2D

var input: Vector2
@export var power: float

func _physics_process(delta):
	var velocity = Vector2.ZERO
	input = Vector2(Input.get_axis("ui_left", "ui_right"), Input.get_axis("ui_up", "ui_down")).normalized()
	velocity = input * power
	if input.x == 0:
		velocity.x = 0
	if input.y == 0:
		velocity.y = 0
	position += velocity * delta


func _on_time_1_bullet_hit(result, bulletIndex, spawner):
#	spawner.free_bullet_to_pool(bulletIndex) #can be used if returnBulletsToPoolAutomatically is false (see documentation on README)
	print("hit ", result[0]["collider"])
