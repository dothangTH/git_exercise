bool valid(const int WIDTH 800, const int HEIGHT 600, char direction, int x, int y)
{
    switch (direction) {
    case 72:
        if (y >= 0) return true;
        else return false;
        break;
    case 75:
        if (x >= 0) return true;
        else return false;
        break;
    case 77:
        if (x < (WIDTH-100) return true;
        else return false;
        break;
    case 80:
        if (y < (HEIGHT - 100)) return true;
        else return false;
        break;
    }
}


