extends Resource
class_name PatternSpawnerData

enum TimerMode {
	Idle,
	Physics
}

@export var ID: int
@export var time: float
@export var timerMode: TimerMode
