@tool
extends EditorPlugin


func _enter_tree():
	add_custom_type("BulletBorder", "Node2D", preload("res://addons/PerfBullets/GDScript_Classes/BulletBorder.gd"), preload("res://addons/PerfBullets/Icons/BulletBorder.svg"))
	add_custom_type("PatternManager", "Node", preload("res://addons/PerfBullets/GDScript_Classes/PatternManager.gd"), preload("res://addons/PerfBullets/Icons/PatternManager.svg"))


func _exit_tree():
	pass
