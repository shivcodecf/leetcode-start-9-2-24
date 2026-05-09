class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {

        int score = 0, counter = 0;

        for (int i = 0; i < events.size(); i++) {
            if(counter>=10)
            {
                break;
            }
            if (events[i] == "W") {
                counter++;
            } else if(events[i]=="WD" || events[i]=="NB"){
                score ++;
            } else {

                score+=stoi(events[i]);

            }
        }

        return {score, min(counter,10)};
    }
};