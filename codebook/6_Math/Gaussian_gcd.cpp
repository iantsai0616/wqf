double a[110][110];
const double eps = 1e-7;
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n + 1; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        int mx = i;
        for(int j = i + 1; j <= n; j++){
            if(fabs(a[j][i]) > fabs(a[mx][i])) mx = j;
        }
        swap(a[i], a[mx]);
        if(fabs(a[i][i]) < eps){
            continue;
        }
        for(int j = n + 1; j >= i; j--){
            a[i][j] /= a[i][i];
        }
        for(int j = i + 1; j <= n; j++){
            for(int k = n + 1; k >= i; k--){
                a[j][k] -= a[i][k] * a[j][i];
            }
        }
    }
    for(int i = n; i >= 1; i--){
        for(int j = i + 1; j <= n; j++){
            a[i][n + 1] -= a[i][j] * a[j][n + 1];
        }
        if(a[i][i] == 0){
            cout << "No Solution";
            return;
        }
        //a[i][i] = 0 and a[i][n + 1] == 0 無限多解
        //a[i][i] = 0 and a[i][n + 1] != 0 無解
    }
    cout << fixed << setprecision(2);
    for(int i = 1; i <= n; i++){
        cout << a[i][n + 1] << '\n';
    }
}