@tool
extends EditorPlugin


func _enter_tree():
	add_custom_type("BulletBorder", "Node2D", preload("res://addons/PerfBullets/GDScript_Classes/BulletBorder.gd"), preload("res://addons/PerfBullets/Icons/BulletBorder.svg"))
	add_custom_type("PatternManager", "Node", preload("res://addons/PerfBullets/GDScript_Classes/PatternManager.gd"), preload("res://addons/PerfBullets/Icons/PatternManager.svg"))
	add_custom_type("PatternSpawnerData", "Resource", preload("res://addons/PerfBullets/GDScript_Classes/PatternSpawnerData.gd"), preload("res://addons/PerfBullets/Icons/PatternSpawnerData.svg"))


func _exit_tree():
	pass
