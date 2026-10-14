#include <superkarel.h>

void turn_right();
void face_to_north();
void face_to_south();
void face_to_east();
void face_to_west();
int jump_right();
int jump_left();

int main() {
	turn_on("task_1.kw");
    
    put_beeper();
    jump_right();
    jump_left();
    face_to_west();

    turn_off();
    return 0;
}

int jump_left() {
    while (true) {
        face_to_north();
        step();
        if (beepers_present()) {
                pick_beeper();
                break;
        }   
        while (left_is_blocked() && front_is_clear()) {
                step();
                if (beepers_present()) {
                        pick_beeper();
                        return 0;
                }             
        }
        face_to_west();
        step();
        if (beepers_present()) {
                pick_beeper();
                break;
        } 
        while (left_is_blocked() && front_is_clear()) {
                step();
                if (beepers_present()) {
                        pick_beeper();
                        return 0;
                }
        } 
        face_to_south();
        step();
        if (beepers_present()) {
                pick_beeper();
                break;
        }
        while (left_is_blocked() && front_is_clear()) {
                step();
                if (beepers_present()) {
                        pick_beeper();
                        return 0;
                }    
        }
    }
}

int jump_right() {
    while (true) {
        face_to_north();
        step();
        if (beepers_present()) {
                 pick_beeper();
                 break;
        }
        while (right_is_blocked() && front_is_clear()) {
                step();
                if (beepers_present()) {
                        pick_beeper();
                        return 0;
                }
        }
        face_to_east();
        step();
        if (beepers_present()) {
                pick_beeper();
                break;
        }
        while (right_is_blocked() && front_is_clear()) {
                step();
                if (beepers_present()) {
                        pick_beeper();
                        return 0;
                }
        }
        face_to_south();
        step();
        if (beepers_present()) {
                pick_beeper();
                break;
        }
        while (right_is_blocked() && front_is_clear()) {
                step();
                if (beepers_present()) {
                        pick_beeper();
                        return 0;
                }
        }
    }
}

void turn_right() {
	set_step_delay(0);
	loop (3) {
		turn_left();
	}
	set_step_delay(100);
}

void face_to_north() {
	set_step_delay(0);
	while (!facing_north()) {
		turn_left();
	}
	set_step_delay(100);
}

void face_to_south() {
	set_step_delay(0);
	while (!facing_south()) {
		turn_left();
	}
	set_step_delay(100);
}

void face_to_east() {
	set_step_delay(0);
	while (!facing_east()) {
		turn_left();
	}
	set_step_delay(100);
}

void face_to_west() {
	set_step_delay(0);
	while (!facing_west()) {
		turn_left();
	}
	set_step_delay(100);
}
