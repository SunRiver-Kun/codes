using System;

namespace 控制网设计与平差
{
    public class Vector3
    {
        public float x, y, z;

        public Vector3(float x = 0f, float y = 0f, float z = 0f)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public static Vector3 operator +(Vector3 a, Vector3 b)
        {
            return new Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
        }

        public static Vector3 operator -(Vector3 a, Vector3 b)
        {
            return new Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
        }

        public static Vector3 operator *(Vector3 a, float b)
        {
            return new Vector3(a.x * b, a.y * b, a.z * b);
        }

        public static Vector3 operator /(Vector3 a, float b)
        {
            return new Vector3(a.x / b, a.y / b, a.z / b);
        }

        // a·b
        public float Dot(Vector3 other)
        {
            return this.x * other.x + this.y * other.y + this.z * other.z;
        }

        // a x b
        public Vector3 Cross(Vector3 other)
        {
            return new Vector3(this.y * other.z - this.z * other.y,
                    this.z * other.x - this.x * other.z,
                    this.x * other.y - this.y * other.x);
        }

        public override string ToString()
        {
            return string.Format("({0,2:F2}, {1,2:F2}, {2,2:F2})", this.x, this.y, this.z);
        }

        public bool Equals(Vector3 other)
        {
            return x == other.x && y == other.y && z == other.z;
        }

        public float DistSq(Vector3 other)
        {
            return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z);
        }

        public float Dist(Vector3 other)
        {
            return MathF.Sqrt(DistSq(other));
        }

        public float LengthSq()
        {
            return this.x * this.x + this.y * this.y + this.z * this.z;
        }

        public float Length()
        {
            return MathF.Sqrt(LengthSq());
        }

        public Vector3 Normalize()
        {
            float len = Length();
            if (len > 0f)
            {
                x /= len;
                y /= len;
                z /= len;
            }
            return this;
        }

        public Vector3 GetNormalized()
        {
            return this / Length();
        }
    }
}