@icon("res://addons/PerfBullets/Icons/PatternManager.svg")
extends Node
##A class that manages when each Spawner is activiated. Have one of these as a direct child of every node using Spawners.
##Also create a Timer node with the EXACT name as the Spawner (It is used to find which Spawner is is referenceing).
class_name PatternManager

##The signal that activates each spawner once the timer has run out
signal start(node_id: int)

##The Array that houses each of the Spawners controlled by the PatternManager
@export var data: Array[PatternSpawnerData]
var spawners: Array

func _ready():
	spawners = find_spawners(get_parent())
	for i in data:
		var spawnerToUse
		for j in spawners:
			if j.ID == i.ID:
				spawnerToUse = j
		if spawnerToUse.startMode == 1:
			connect("start", Callable(spawnerToUse, "start_node"))
		var timer = Timer.new()
		timer.wait_time = i.time
		timer.one_shot = true
		timer.process_mode = i.timerMode
		timer.name = str(spawnerToUse.get_id())
		add_child(timer)
		timer.connect("timeout", Callable(self, "emit_ready").bind(spawnerToUse.get_id()))
		timer.start()

func emit_ready(node_id:int):
	emit_signal("start", node_id)

## Will find all of the spawners in the scene starting from the parent of the PatternManager
func find_spawners(startingNode: Node) -> Array:
	var found_nodes = []
	if startingNode is Spawner:
		found_nodes.append(startingNode)
	for child in startingNode.get_children():
		if child is Node:
			found_nodes += find_spawners(child)
	return found_nodes
