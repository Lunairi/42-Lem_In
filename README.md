# Algorithm

    1) Read + Parse room information
        1) use GNL to read lines.
        2) GNL until a line of format "%d" is found, then ft_atoi this value into an integer. These are our ants
        3) next, use GNL in a loop to read room information.
            1) if line[0] == #
                1) if line[1] == #
                    1) set start or end flag
                2) free and get_next_line
            2) else
                1) if line in format "%s %d %d"
                    1) create new linked list node. parse line into node.name, node.x, node.y
                    2) add to end of list.
                2) else
                    1) if line in format "%d-%d"
                        1) create hash table from linked list
                        2) free linked list?
                        3) add link to hash table
                        4) free line
                        5) break loop
        4) next, use GNL in a loop to read link info
            1) if (line[0] == #)
                1) free and get_next_line
            2) else
                1) if line in format "%d %d"
                    1) add to hash table
                2) free line
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

# To Do:

    1) Parser
    2) Struct methods
    3) Hash function

# Hash function notes:

    1) possible implementations:  
        1) use the values of each character in the name as a number in base 128 (ie, str[0] + str[1] * 128 + str[2] * 128 ** 2 ...)
            1) pros:
                1) Provided that the strings are different enough, the values are guaranteed to be unique.
            2) cons
                1) can only process 4 characters in this manner
                2) must allocate MUCH more memory than necessary in order to use the hash values effectively without additional processing.
        2) similar to 1, but instead of using all characters 0 - 127, create a null-terminated string of characters that appear in room names, then use the size of the array as the base
            1) pros:
                1) average-case range should allow for significantly improved process length.
                2) hash values still guaranteed to be unique
            2) cons:
                1) worst case range is still the same as 1)
                2) still have to allocate a lot of space in order to use hash values effectively
        3) Use modified Huffman coding algorithm to generate hash values based on frequency of characters in list of names
            1) pros:
                1) Should compress range down even more
            2) cons:
                1) Still no effective way to use hash values as indices.
        1) Create an n-ary tree from the room names
            1) pros:
                1) If done correctly, should be able to generate correct range from 0 - #rooms - 1
                2) should be reasonably fast
            2) cons
                1) Will require persistent storage - n-ary tree cannot be deleted until after all ants go through
                2) have to create an n-ary tree.

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
