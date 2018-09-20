//#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")//去除CMD窗口
#include <dlib/opencv.h>  
#include <opencv2/opencv.hpp>  
#include <dlib/image_processing/frontal_face_detector.h>  
#include <dlib/image_processing/render_face_detections.h>  
#include <dlib/image_processing.h>  
#include <dlib/gui_widgets.h>  
#include<fstream>
#include<iostream>
/*#include <fstream>
#include <iostream>
using namespace std;
int main()
{    char str2[100];    
int i=0;
if (!infile) { cout << "open error!" << endl;  exit(
ifstream infile("123.txt",ios::in);要在存放VC++MyProjects里面的当前文件建立一个txt文本 位置也可以改成其它地方1); }
char str;
while (infile.get(str))//从文件读取字符   
{  if(str=='3')   str=' ';//如果要把3改成其它字符则把空格换成其它字符   s
tr2[i++]=str; }
str2[i]='\0';
infile.close();//关闭文件 
ofstream outfile("123.txt",ios::out);//存放位置可以改成其他地方如c:fl.txt
if(!outfile) {     cout<<"open eror!"<<endl;     exit(1); } i=0;
while(str2[i])//从文件读取字符 
{  outfile.put(str2[i]);//输出到文件fl.txt中  i++; } 
outfile.close();//关闭文件
return 0;}
/////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <cstdlib>
using namespace std;
void main()
{
fstream file("in.txt");
string line;
int n,count=0;
ofstream outfile("in2.txt",ios::out|ios::trunc);
cout<<"Please input the line number you want to del:"<<endl;
cin>>n;
while(!file.eof())
{
getline(file,line);
if(count!=n-1)//如果要修改内容就在这修改line的内容,再存到文件中就行了
outfile<<line<<endl;
count++;
}
outfile.close();
file.close();
ofstream outfile1("in.txt",ios::out|ios::trunc);
fstream file1("in2.txt");
while(!file1.eof())
{
getline(file1,line);
outfile1<<line<<endl;
}
outfile1.close();
file1.close();1
system("del in2.txt");//删除中间文件
}


*/
using namespace dlib;
using namespace std;
//using namespace cv;
using namespace cv::ml;
int main()
{
	//fstream file("in.txt");
	string line;
	//int n, count = 0;
	ofstream outfile("C:\\Users\\Paul Xia\\Desktop\\ReadByPost.txt", ios::out | ios::trunc);

	//***************文件传输1
	ofstream fout;
	string filename = "C:/Users/Paul Xia/Desktop/ReadByUnity.txt";
	fout.open(filename.c_str(), ios_base::out | ios_base::ate);
	if (!fout.is_open()) return 0;
	//***************文件传输2
	try
	{
		cv::VideoCapture cap(0);
		//cv::VideoCapture capcap(1);
		if (!cap.isOpened())
		{
			cerr << "Unable to connect to local camera" << endl;
			return 1;
		}
		/*if (!capcap.isOpened())
		{
			cerr << "Unable to connect to local camera" << endl;
			return 1;
		}
		*/
		//image_window win;  

		// Load face detection and pose estimation models.  
		frontal_face_detector detector = get_frontal_face_detector();
		shape_predictor pose_model;
		deserialize("shape_predictor_68_face_landmarks.dat") >> pose_model;

		cv::Ptr<SVM> svm = StatModel::load<SVM>("E:\\小学期创新实验\\Project1\\Project1\\SVM_DATA.xml");
		int i=0;
		// Grab and process frames until the main window is closed by the user.  
		while (cv::waitKey(20) != 27)
		{
			// Grab a frame  
			cv::Mat temp;//tempt;
			cap >> temp; //capcap >> tempt;

			cv_image<bgr_pixel> cimg(temp); //cv_image<bgr_pixel> cimgt(tempt);
			// Detect faces   
			std::vector<rectangle> faces = detector(cimg); //std::vector<rectangle> facest = detector(cimgt);
			// Find the pose of each face.  
			std::vector<full_object_detection> shapes;
			for (unsigned long i = 0; i < faces.size(); ++i)
				shapes.push_back(pose_model(cimg, faces[i]));

			if (!shapes.empty()) {
				float testData[1][136];
				float 系数 = -(faces[0].top() - faces[0].bottom()) / 300.0;
				for (int i = 0; i < 68; i++) {
					circle(temp, cvPoint(shapes[0].part(i).x(), shapes[0].part(i).y()), 2, cv::Scalar(255, 0, 0), -1);
					testData[0][i * 2] = (shapes[0].part(i).x() - faces[0].left()) / 系数;
					testData[0][i * 2+1] = (shapes[0].part(i).y() - faces[0].top()) / 系数;
					//  shapes[0].part(i).x();//68个  
				}
				cv::Mat 结果;
				
				cv::Mat query(1, 136, CV_32FC1, testData);

				if (svm->predict(query) == 250) 
				{
					i++;
					cv::putText(temp, "Happy" , cv::Point(20, 60),3, 2, cvScalar(0, 0, 255));
					//cout << "高兴" << endl;
					if (i >= 32)
					{
						cout << "高兴" << endl;
						outfile << 0 << endl;
						fout << 0 << endl;
						i = 0;
					}//outfile.close();
					/*file.close();
					ofstream outfile1("in.txt", ios::out | ios::trunc);
					fstream file1("in2.txt");
					getline(file1, line);
					outfile1 << line << endl;
					outfile1.close();
					file1.close();
					//system("del in2.txt");//删除中间文件
	*/
	}
					
				if (svm->predict(query) == 170) {
					i++;
					cv::putText(temp, "Normal", cv::Point(20, 60), 3, 2, cvScalar(0, 0, 255));
					//cv::waitKey(5000);
					//cout << "平静" << endl;
					if (i >= 32)
					{
						cout << "平静" << endl;
						outfile << 1 << endl;
						fout << 1 << endl;
					i = 0;
					}
					//outfile.close();
		/*			file.close();
					ofstream outfile1("in.txt", ios::out | ios::trunc);
					fstream file1("in2.txt");
					getline(file1, line);
					outfile1 << line << endl;
					outfile1.close();
					file1.close();
					//system("del in2.txt");//删除中间文件
	*/
	                  }
				if (svm->predict(query) == 300) {
					i++;
					cv::putText(temp, "Sad", cv::Point(20, 60), 3, 2, cvScalar(0, 0, 255));
					
					if(i >= 32)
					{
						cout << "悲伤" << endl;
						outfile << 2 << endl;
						fout << 2 << endl;
						i = 0;
					}//outfile.close();
	/*				file.close();
					ofstream outfile1("in.txt", ios::out | ios::trunc);
					fstream file1("in2.txt");
					getline(file1, line);
					outfile1 << line << endl;
					outfile1.close();
					file1.close();
					//system("del in2.txt");//删除中间文件
	*/
	}
				//	cout<<	svm->predict(query)<<endl;
			//	cout << 结果 << endl;
			}
			//Display it all on the screen  
			imshow("表情识别      ESC退出", temp);

		}
	}
	catch (serialization_error& e)
	{
		cout << "You need dlib's default face landmarking model file to run this example." << endl;
		cout << "You can get it from the following URL: " << endl;
		cout << "   http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2" << endl;
		cout << endl << e.what() << endl;
	}
	catch (exception& e)
	{	
		cout << e.what() << endl;
	}
	system("pause");
}