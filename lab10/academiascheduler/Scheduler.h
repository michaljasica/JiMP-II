//
// Created by malikmontana on 14.05.18.
//

#ifndef JIMP_EXERCISES_SCHEULDER_H
#define JIMP_EXERCISES_SCHEULDER_H

#include <vector>
#include <cstddef>
#include <algorithm>

namespace academia{
    class SchedulingItem{
    public:
        SchedulingItem(int course,int teacher,int room,int time, int year):course_id(course),teacher_id(teacher),room_id(room),time_slot(time),year_(year){};
        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;
        int time_slot;
    private:
        int course_id;
        int teacher_id;
        int room_id;

        int year_;
    };

    class Schedule{
    public:

        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const ;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;

        SchedulingItem operator[](int x) const;

    private:
        std::vector<SchedulingItem> schedules;

    };

    class Scheduler{
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots)=0;

    private:
    };

    class NoViableSolutionFound:public std::invalid_argument{
    public:
        NoViableSolutionFound(): std::invalid_argument("Invalid argument"){};

    };

    class GreedyScheduler : public Scheduler{
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;

    };
};


#endif //JIMP_EXERCISES_SCHEULDER_H
