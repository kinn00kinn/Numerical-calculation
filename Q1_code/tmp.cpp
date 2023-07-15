/*ピボット選択関数*/
void pivot()
{
    int n = a.size();
    int max, max_pos, tmp_s;
    vector<double> tmp_v;
    // pivot
    for (int i = 0; i < n; i++)
    {
        max = abs(a[i][0]);
        max_pos = 0;
        for (int j = 0; j < n; j++)
        {
            if (max < abs(a[i][j]))
            {
                max = a[i][j];
                max_pos = j;
            }
        }
        // a
        tmp_v = a[max_pos];
        a[max_pos] = a[i];
        a[i] = tmp_v;
        // b
        tmp_s = b[max_pos];
        b[max_pos] = b[i];
        b[i] = tmp_s;
    }
}