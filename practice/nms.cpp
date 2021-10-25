

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
typedef struct Detect
{
       int x1;
       int y1;
       int x2;
       int y2;
       float score;
}Bbox;
float myIou(Bbox a, Bbox b)
{
       int x11 = std::max(a.x1, b.x1);
       int y11 = std::max(a.y1, b.y1);
       int x22 = std::min(a.x2, b.x2);
       int y22 = std::min(a.y2, b.y2);
       int interArea = (y22 - y11)*(x22 - x11);
       float Iou = 1.0*interArea/((a.x2 - a.x1)*(a.y2 - a.y1) + (b.x2 - b.x1)*(b.y2 - b.y1) - interArea);
       return Iou;
}

float getIou(Bbox area1,Bbox area2)
{
      auto xx1 = max(area1.x1,area2.x1);
      auto yy1 = max(area1.y1,area2.y1);
      auto xx2=min(area1.x2,area2.x2);
      auto yy2 = min(area1.y2,area2.y2);

      int  area11 = (area1.x2-area1.x1)*(area1.y2-area1.y1);
      int area22 = (area2.x2-area2.x1)*(area2.y2-area2.y1);

      int intersection=(yy2-yy1)*(xx2-xx1);
      int unionSection=(area11+area22);
      
      float IOU = 1.0*intersection/(unionSection-intersection);
      return IOU;
}
bool cmp(Bbox a, Bbox b)
{
       return a.score > b.score;
}
vector <Bbox> myNMS(vector<Bbox>&boxes, float thresh)
{
       vector <Bbox> results;
       sort(boxes.begin(), boxes.end(), cmp);
       for (int i = 0; i < boxes.size()-1; i++)
       {
              results.push_back(boxes[i]);
              for (int j = i + 1; j < boxes.size(); j++)
              {
                     float myiou = getIou(boxes[i], boxes[j]);
                     if (myiou > thresh)
                     {
                           boxes.erase(boxes.begin() + j);
                           j = j - 1;
                     }
              }
       }
       return results;
}

void myNMS2(vector<Bbox>&boxes, float thresh)
{
    sort(boxes.begin(), boxes.end(),cmp);
    for(int i = 0; i<boxes.size()-1; i++)
    {
        for(int j = i+1; j<boxes.size(); j++)
        {
            float thresh1 = getIou(boxes[i],boxes[j]);
            if(thresh1 > thresh)
            {
                boxes.erase(boxes.begin() + j);
                j--;
            }
        }

    }
}

int main(void)
{
       Bbox bboxes[6] = { { 100, 100, 210, 210, 0.72 },{ 250, 250, 420, 420, 0.8 },{ 220, 220, 320, 330, 0.92 },{ 100, 100, 210, 210, 0.72 }, { 230, 240, 325, 330, 0.81 },{220, 230, 315, 340, 0.9} };
       vector<Bbox> bb;
       for (auto &b : bboxes)
       {
              bb.push_back(b);
       }
       myNMS2(bb, 0.7);
       for (auto &c : bb)
       {
              cout << c.x1<<" "<<c.x2<<" "<<c.y1<<" "<<c.y2<<" "<<c.score << endl;
       }
       //cout << myIou(bb[0],bb[2]) << endl;
    //    system("pause");
       return 0;
}
