//
// Created by malikmontana on 28.04.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

namespace moviesubs{
    class MovieSubtitles {
    public:
        MovieSubtitles() =default;
        ~MovieSubtitles();

        virtual void ShiftAllSubtitlesBy(int delay, int fps, std::stringstream*in, std::stringstream* out)=0;
    };

    class MicroDvdSubtitles: public MovieSubtitles  {
    public:
        MicroDvdSubtitles();
        ~MicroDvdSubtitles();

        void delay(const char* in, const char* out,int delay, int fps);
        void ShiftAllSubtitlesBy(int delay, int fps, std::stringstream*in, std::stringstream* out) override;
    private:
        int delay_;
        int fps_;
        std::stringstream*in_;
        std::stringstream out_;
    };

    class SubRipSubtitles : public MovieSubtitles{
    public:
        SubRipSubtitles() {

        }

        ~SubRipSubtitles();

        virtual void ShiftAllSubtitlesBy(int delay, int fps, std::stringstream*in, std::stringstream* out) override;

    };

    class NegativeFrameAfterShift:public std::invalid_argument{
    public:
        NegativeFrameAfterShift():invalid_argument("Wrong framerate"){};
    };

    class SubtitleEndBeforeStart:public std::invalid_argument{
    public:
        SubtitleEndBeforeStart(int where,std::string text):invalid_argument("At line "+std::to_string(where)+": "+text),where_{where}{};
        int LineAt() const;
        //int what() const;
    private:
        int where_;
    };

    class InvalidSubtitleLineFormat:public std::invalid_argument{
    public:
        InvalidSubtitleLineFormat():invalid_argument("Wrong framerate"){};
    };

    class EndFrameLaterThanStartFrame:public std::invalid_argument{
    public:
        EndFrameLaterThanStartFrame():invalid_argument("Wrong framerate"){};
    };

    class NegativeFrameRateAfterShift: public std::invalid_argument{
    public:
        NegativeFrameRateAfterShift():invalid_argument("Wrong framerate"){};
    };

    class MissingTimeSpecification: public std::invalid_argument{
    public:
        MissingTimeSpecification():invalid_argument("Wrong framerate"){};
    };

    class OutOfOrderFrames: public std::invalid_argument{
    public:
        OutOfOrderFrames():invalid_argument("Wrong framerate"){};
    };
}



#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
