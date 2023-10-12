extends Node2D

@onready var enemy = $Enemy
@onready var enemy_label = $Enemy/Label

@onready var starting_pos:int
@onready var ending_pos: int = get_node("BulletBorder").get_child(1).position.x
var multiplier = 1 
@export var power = 5
# Called when the node enters the scene tree for the first time.
func _ready():
	starting_pos = position.x

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	if enemy.position.x > ending_pos or enemy.position.x < starting_pos:
		multiplier *= -1
	enemy.position.x += power * multiplier


var enemy_counter = 0
func _on_spawner_bullet_hit(result, bulletIndex, spawner):
	if result[0]["collider"] == enemy:
		enemy_counter += 1
		enemy_label.text = str(enemy_counter)
