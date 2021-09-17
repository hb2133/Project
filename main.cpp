#include <SDL.h>
/* 변경사항
1. 해상도 800,480 으로 변경
2. 색상 노란색으로 변경
3. Delay를 이용해 3초 뒤 종료
4. title 명 "SDL Project"로 변경
5. g_bRunning은 init 함수를 통해 window를 생성했는지 나타내줄 bool형 변수*/
SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

void Render();
bool init(const char* title, int xpos, int ypos, int height, int width, int flags);

int main(int argc, char* args[])
{
  if(init("SDL Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,800,480,SDL_WINDOW_SHOWN))
  {
    g_bRunning = true;
  }

  while(g_bRunning)
  {
    Render();
    SDL_Delay(3000); //3초뒤에 g_bRunning false로 변경
    g_bRunning= false;
  }

  return 0;
}

//window 함수
bool init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
  {
    g_pWindow = SDL_CreateWindow(title,xpos,ypos,height, width, flags);
    if(g_pWindow!=0)
    {
      g_pRenderer = SDL_CreateRenderer(g_pWindow,-1,0);
    }
  }
  else{
    return false;
  }

  SDL_SetRenderDrawColor(g_pRenderer,255,255,125,255);
  return true;
}

//Renderer 함수
void Render()
{
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);
}

