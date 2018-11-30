내비어-스톡스 방정식(Navier-Stokes equation)은 바로 유체(fluid), 즉 공기나 물 등 흐른다고 생각할 수 있는 것들에 대한 운동방정식입니다. 이 방정식도 사실 기본은 뉴튼의 운동방정식과 몇 가지 추가적인 가정에서 따라나오는데 유도 과정에 담긴 기본 아이디어는 유체를 매우 작은 조각들의 합으로 보고, 각각의 조각들이 서로 어떻게 상호작용하면서 움직이는지를 생각한 것입니다. 내비어-스톡스 방정식에서 매우 이상적인 상황은 
 - 구체적으로 유체가 비압축이고, 시간에 따라 상황이 변하지 않으며, 마찰이 없고 오직
중력장의 영향만 받아 운동하는 상황을 가정하면 내비어 스톡스 방정식은 
베르누이방정식으로 바뀝니다. 
베르누이 방정식은 1/2pv^2 + pgh + p = constant 로 주어지는데 여기서 
p : 밀도
v : 속도
g : 중력가속도
h : 높이
p : 압력
입니다. 여기서 g를 빼고는 모두 위치마다 값이 다를 수 있기 때문에 정확히 말하면 위의
양들은 하나의 값이라기 보다는 위치에 대한 함수가 됩니다. 이 방정식으로 많은 것을 
알 수 있습니다. 예를 들어 비행기의 날개가 어떻게 양력을 얻는지 위 방정식으로 부터 알아봅시다. 이 경우 유체는 공기가 되는데, 물론 공기는 점성도 있고 압축도 되며 마찰도 있긴
하지만, 지금 상황에서는 이것들을 무시하고도 충분히 좋은 물리적 설명이 가능합니다.
비행기 날개 밑을 지나는 공기보다 위를 지나는 공기가 훨씬 빠른데 날개 위쪾과 밑쪽 모두
단위면적당 들어오는 공기양과 빠져나가는 공기양이 일정하기 때문에 밀도는 크게 다르지 않습니다. 날개 위나 아래 모두 높이가 크게 차이나지 않기 때문에 이에 의한 효과 역시 크지 않습니다. 따라서 베르누이 방정식으로부터, 속도가 빠른 윗부분의 압력이 아래보다 낮아지게 되고
, 날개 밑과 위의 압력차에 의해 날개가 위로 힘을 받게 됩니다. 하지만 엄밀히 말하면 공기는
압축도 가능하고, 점성도 있고, 마찰려도 있으며, 공기역학적으로 날개가 잘못 설계되면 날개 뒷부분이라든가에 난류도 생기는 등 매우 복잡한 요소들이 들어갑니다. 그리고 이를 다 고려하기 위해서 바로 내비어-스톡스 방정식이 필요하게 되는 것입니다.
