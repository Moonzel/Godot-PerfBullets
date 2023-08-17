@icon("res://addons/PerfBullets/Icons/PatternManager.svg")
extends Node
##A class that manages when each Spawner is activiated. Have one of these as a direct child of every node using Spawners.
##Also create a Timer node with the EXACT name as the Spawner (It is used to find which Spawner is is referenceing).
class_name PatternManager

##The signal that activates each spawner once the timer has run out
signal start(node_name: String)

func _ready():
	for i in get_children():
		if i is Timer:
			i.connect("timeout", Callable(self, "emit").bind(i.get_name()))
			i.start()
			i.one_shot = true

func emit(node_name:String):
	emit_signal("start", node_name)
