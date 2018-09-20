using UnityEngine;
using System.Collections;
using System;
using System.Diagnostics;
using System.IO;
using System.Text;
using System.Threading;

namespace game
{
    public class Myprocess : MonoBehaviour
    {
        public int ctrl = 0;
        public int line_num = 0;
        public void start1()
        {

            FileStream aFile = new FileStream("C:\\Users\\Paul Xia\\Desktop\\ReadByUnity.txt", FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
            StreamReader sr = new StreamReader(aFile);
            String line;

            while ((line = sr.ReadLine()) != null)
            {
                ctrl = int.Parse(line);
                line_num++;
                //Thread.Sleep(5000);
            }




        }
    }
}
