# Algorithm

    1) Read + Parse room information
    2) Initialize array of linked list nodes with size = # rooms.
    3) Hash each room and generate unique index within range (0 - #rooms - 1)
    4) Foreach link in list of links:
        1) parse start and end rooms
        2) add end room to start bucket
        3) add start room to end bucket
    5) Foreach curr_room in list of rooms:
        1) create pathway through curr_room, from start to end, by creating two lists that share only curr_room
            1) create two paths - one starting at curr_room[0] and one starting at curr_room[1]
            2) continue down each path using the first available room for each.
            3) if one path hits a start or end flag, set the corresponding flag
            4) if no more rooms available, start backtracking, and set invalid flag for last visited room.
    6) Foreach curr_room in list of rooms:
        1) if invalid flag set, remove that room from all rooms it's connected to, then set the pointer to NULL
    7) while #ants > 0 && received_ants != orig_#_ants
        1) Check ant_flags of all rooms connected to start room
            1) if any unset
                1) set, and subtract from #_ants
            2) else
                1) foreach room in curr_room's rooms
                    1) check if room has unset ant_flags
                        1) if room has unset ant_flag
                            1) move ant to next room
                            2) go back and move all previous ants.
                        2) if room is exit
                            1) add all ants in ants queue to received_ants
                            2) empty ants queue
                            3) move ants
                            4) go back and move all previous ants
                        3) else
                            1) start loop on next room.
        2) take snapshot, print out.

<!--
    1) start-list
      1) init start-list(curr_room)
      2) foreach prospective_room in curr_room bucket:
        1) if prospective_room->start, return list
        2) if prospective_room not in start-list, add to start-list, change curr_room to new room
      3) if no prospective rooms available, remove last room, backtrack
    2) end-list
      1) init end-list(curr_room)
      2) foreach prospective_room in curr_room bucket:
        1) if prospective_room->end, return list
        2) if prospective_room not in start-list or end-list, add to end-list, change curr_room to new room
      3) if no prospective rooms available, mark last room as -1, remove, backtrack
    -->
