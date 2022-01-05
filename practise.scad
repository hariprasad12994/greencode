length = 120;
tail = 20;
// todo: decide whether a separate tail sections are needed
// effective_length = length - tail;
effective_length = length;
width = 60;
slot_width = 3;
segment_count = 8;
minimum_distance_between_slots = 5;

// l / n is limited by pecision in real world. add a precision factor
// another limitation segment_length >= minimum_distance_btn_slots to avoid the fragility of divider. but is it a not problem in a thicker divider. in fact in a thicker divider we can have straight line slots, this must be verified physically
segment_length = (effective_length / segment_count) - slot_width;
echo("segment length = ", round(segment_length)); 

for(count  = [0: segment_count]){
    if(count * (segment_length + slot_width) < effective_length){
        translate([count * (segment_length + slot_width), 0, 0]) {
            polygon(points = [
                [0, 0], 
                [segment_length / 2, 0], 
                [segment_length / 2, width],
                [0, width]
            ]);
            polygon(points = [
                [segment_length / 2, 0], 
                [segment_length / 2 + slot_width, 0],  
                [segment_length / 2 + slot_width, width / 2], 
                [segment_length / 2, width / 2]
            ]);
            polygon(points = [
                [segment_length / 2 + slot_width, 0], 
                [segment_length / 2 + slot_width + segment_length / 2, 0], 
                [segment_length / 2 + slot_width + segment_length / 2, width], 
                [segment_length / 2 + slot_width, width]
            ]);
        }
    }
}
