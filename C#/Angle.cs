using System;

namespace 控制网设计与平差
{
    public class Angle
    {
        public float degree { get { return (int)(m_sec / 3600f); } }
        public float min { get { return (int)((m_sec - sec) / 60.0) % 60; } }
        public float sec { get { int integer = (int)m_sec; return integer % 60 + (m_sec - integer); } }
        public float data { get { return m_sec; } }

        public Angle(float degree = 0, float min = 0, float sec = 0)
        {
            m_sec = degree * 3600 + min * 60 + sec;
        }

        public static Angle operator +(Angle a, Angle b)
        {
            return new Angle(0, 0, a.m_sec + b.m_sec);
        }

        public static Angle operator -(Angle a, Angle b)
        {
            return new Angle(0, 0, a.m_sec - b.m_sec);
        }

        public static Angle operator *(Angle a, float b)
        {
            return new Angle(0, 0, a.m_sec * b);
        }

        public static Angle operator *(float b, Angle a)
        {
            return new Angle(0, 0, a.m_sec * b);
        }

        public static Angle operator /(Angle a, float b)
        {
            return new Angle(0, 0, a.m_sec / b);
        }

        public static bool operator <(Angle a,Angle b)
        {
            return a.m_sec < b.m_sec;
        }

        public static bool operator >(Angle a, Angle b)
        {
            return a.m_sec > b.m_sec;
        }

        public static bool operator ==(Angle a,Angle b)
        {
            return a.m_sec == b.m_sec;
        }

        public static bool operator !=(Angle a, Angle b)
        {
            return a.m_sec != b.m_sec;
        }

        public bool Equal(Angle other)
        {
            return m_sec == other.m_sec;
        }

        public override string ToString()
        {
            return String.Format("{0,2:F0}°{1,2:F0}′{2,2:F2}″", degree, MathF.Abs(min), MathF.Abs(sec));
        }

        private float m_sec;
    }
}