@icon("res://addons/PerfBullets/Icons/BulletBorder.svg")
extends Node2D
##A class that sets the limits that the bullets can go before being returned to the pool
class_name BulletBorder

##The top left point of the box
@export var topLeft: Node2D
##The top right point of the box
@export var bottomRight: Node2D
##The calculated box
var boundaryRect:Rect2


func _ready() -> void:
	update_boundary_rect()

## Function to calculate and update the boundary rectangle based on the positions of the nodes.
func update_boundary_rect() -> void:
	if topLeft != null and bottomRight != null:
		# Calculate the boundaryRect using the positions of topLeft and bottomRight
		boundaryRect = Rect2(topLeft.global_position, bottomRight.global_position - topLeft.global_position)
		# For every spawner, set the player and bounding box
		for child in get_parent().get_children():
			if child is Spawner:
				child.set_bounding_box(boundaryRect)



















#extends Node2D
#class_name BulletBorder
#
## Exported Vector2 variables for the top-left and bottom-right positions.
#@export var topLeftPosition = Vector2(50, 50) : set = set_top_left_position
#@export var bottomRightPosition = Vector2(100, 100) : set = set_bottom_right_position
#
#var boundary_rect
#
#func _ready() -> void:
#	update_boundary_rect()
#
#func update_boundary_rect() -> void:
#	boundary_rect = Rect2(topLeftPosition, bottomRightPosition - topLeftPosition)
#
#	# For every spawner, set the player and bounding box
#	for child in get_parent().get_children():
#		if child is Spawner:
#			child.set_bounding_box(boundary_rect)
#
#func set_top_left_position(value: Vector2) -> void:
#	topLeftPosition = value
#	update_boundary_rect()
#
#func set_bottom_right_position(value: Vector2) -> void:
#	bottomRightPosition = value
#	update_boundary_rect()
