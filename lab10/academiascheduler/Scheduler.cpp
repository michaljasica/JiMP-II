//
// Created by malikmontana on 14.05.18.
//

#include "Scheduler.h"

academia::Schedule academia::Schedule::OfTeacher(int teacher_id) const {
    Schedule tmp;
    copy_if(schedules.begin(),schedules.end(),back_inserter(tmp.schedules),[teacher_id](SchedulingItem item){ return item.TeacherId()==teacher_id;});
    return tmp;
}

academia::Schedule academia::Schedule::OfRoom(int room_id) const {
    Schedule tmp;
    copy_if(schedules.begin(),schedules.end(),back_inserter(tmp.schedules),[room_id](SchedulingItem item){ return item.RoomId()==room_id;});
    return tmp;
}


std::vector<int> academia::Schedule::AvailableTimeSlots(int n_time_slots) const {
    std::vector<int> tmp;
    if(schedules.size()==0){
        for(int i=1;i<=n_time_slots;i++)
            tmp.emplace_back(i);
        return tmp;
    }
    for(int i=1;i<=n_time_slots;i++){
        for(int j=0;j<schedules.size();j++){
            if(schedules[j].TimeSlot()==i)
                break;
            if(j==schedules.size()-1)
                tmp.emplace_back(i);
        }
    }
    return tmp;
}

void academia::Schedule::InsertScheduleItem(const academia::SchedulingItem &item) {
    schedules.emplace_back(item);
}

size_t academia::Schedule::Size() const {
    return schedules.size();
}

academia::SchedulingItem academia::Schedule::operator[](int x) const {
    return schedules[x];
}

academia::Schedule academia::Schedule::OfYear(int year) const {
    Schedule tmp;
    copy_if(schedules.begin(),schedules.end(),back_inserter(tmp.schedules),[year](SchedulingItem item){ return item.Year()==year;});
    return tmp;
}

int academia::SchedulingItem::CourseId() {
    return course_id;
}

int academia::SchedulingItem::TeacherId() {
    return teacher_id;
}

int academia::SchedulingItem::RoomId() {
    return room_id;
}

int academia::SchedulingItem::TimeSlot() const{
    return time_slot;
}

int academia::SchedulingItem::Year() {
    return year_;
}
