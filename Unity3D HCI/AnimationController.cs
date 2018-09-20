using UnityEngine;
using System.Collections;
using System.Diagnostics;
using System;
using System.Threading;


namespace game
{
    public class AnimationController : MonoBehaviour
    {

        private Animator m_Animator = null;
        Myprocess my = new Myprocess();
        private int ll = 0;
        private int tag = 0;

        IEnumerator AnimationWait()
        {
            yield return new WaitForSeconds(6.0f);
            m_Animator.SetInteger("animation", 31);
        }

        void Start()
        {
            m_Animator = GetComponent<Animator>();//获取当前对象的Animator  
        }


        void Update()
        {

            my.start1();
            if (ll != my.line_num)
            {
                if (my.ctrl == 0 && tag == 0)
                {

                    m_Animator.SetInteger("animation", 15);

                }
                //if (my.ctrl == 1)
                //m_Animator.SetInteger("animation", 2);
                //if (my.ctrl == 2)
                //m_Animator.SetInteger("animation", 3);
                if (my.ctrl == 1 && tag == 0)
                {

                    m_Animator.SetInteger("animation", 25);

                }
                if (my.ctrl == 2 && tag == 0)
                {

                    m_Animator.SetInteger("animation", 17);

                }
                if (my.ctrl == 4 && tag == 0)
                {
                    tag = 1;
                    m_Animator.SetInteger("animation", 1);
                }

                if (my.ctrl == 5 && tag == 1)
                {
                    tag = 0;
                    StartCoroutine(AnimationWait());
                }

               
                ll = my.line_num;

            }

        }
    }
}






