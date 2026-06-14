// 12:41
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> counts;
        for (auto &interval : intervals) {
            counts[interval.start]++;
            counts[interval.end]--;
        }
        int ans = 0, curr = 0;
        for (auto &[ts, delta] : counts) {
            curr += delta;
            ans = max(ans, curr);
        }
        return ans;
    }
};
