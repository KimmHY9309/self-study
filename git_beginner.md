# 개요
## pull request를 위한 절차
#### 1. Fork
- 다른 저장소에 있는 프로젝트를 나의 저장소로 가져온다.
- fork가 완료되면 내 계정에 새로운 저장소가 만들어진다.
- 고마움의 표시로 star를 찍어주자 :)
- 코드는 원격 저장소에만 존재한다.
#### 2. clone, remote, fetch, pull
- git clone [url]
- url은 저장소에서 확인할 수 있다.
- git clone 을 하면 원격 저장소에 있는 프로젝트를 내 로컬 저장소로 가져 온다.
- git remote -v 명령어로 현재 프로젝트에 등록된 원격 저장소를 확인할 수 있다.
- clone을 통해 가져온 프로젝트에는 자동으로 origin이 등록되어 있을 것
- git fetch [remote저장소] 를 통해 로컬에는 없지만 저장소에는 있는 데이터를 가져올 수 있다.
- git clone을 한 이후에 원격 저장소에 데이터가 수정된 경우 git fetch를 사용할 것
- 자동으로 merge하지 않으니 수동으로 할 필요가 있다.
- git pull 는 자동 merge 제공
- 코드는 원격저장소와 로컬저장소에 존재한다.
#### 3. branch
- 개발은 여럿이서 진행하므로 작업을 할 때는 원본을 복사에서 독립적으로 개발한다.
- git branch 를 통해 현재 branch를 확인할 수 있다.
- git branch [branchname] 을 통해 생성
- git checkout [branchname] 을 통해 branch 이동
- git checkout -b [branchname] 을 사용한다면 생성과 이동을 같이 진행한다.
- git branch -d [branchname] 을 통해 branch 삭제 가능
#### 4. add, commit, push
- IDE를 통해 코드를 작성하고 저장해도 내 작업폴더에서만 변하지 저장소에는 변화가 없다.
- git status 를 통해 현재 수정사항을 확인할 수 있다.
- git add . : 모든 수정사항을 적용할 준비를 한다
- git commit -m "message" : 로컬저장소에 수정사항을 적용시킨다. message를 통해 어떤 수정사항이 있는지 알려준다.
- git push [origin] [master] : 원격저장소에 수정사항을 적용시킨다. origin은 원격저장소, master는 branch의 대표격
#### 5. pull request 생성
- branch를 생성해 코드를 복사하고 push를 통해 코드를 수정한 경우, branch의 코드는 바뀌었지만 원본 코드(master)는 변하지 않았다.
- master가 실제로 운영되는 서비스이므로, 개발사항을 적용시키기 위해 pull request를 요청한다.
#### 6. review, merge pull request
- pull request를 한 후, 담당자가 확인하고 merge할 경우 branch 코드는 master 코드에 적용된다.
#### 7. branch 삭제 및 동기화
- branch 는 merge 할 때 사라지는 경우도 있고, 직접 삭제할 경우 git branch -d [branchname] 을 사용한다.
- master에는 여러 개발자가 작성한 코드들이 합쳐져 있을 것
- git pull 을 통해 합쳐진 코드들을 가져오고, 다시 branch를 따서 개발을 진행한다 !

## git 되돌리기
- git reset [commit] : 선택한 commit으로 되돌린다. 이후 커밋들은 없어지는 것
- git revert [commit] : 선택한 commit을 없앤다. 선택한 커밋을 취소하는 것이기 때문에 이후 커밋들도 남아있고, 취소하는 커밋이 새로 생성된다.
- "A + a" A에 a를 추가했을 때, reset은 +a를 하기 전으로 돌아 가는 느낌이고 revert 는 -a를 하는 느낌 
- 이미 push를 한 상태라면 reset이 의미가 없기 때문에 revert를 한다. 이 후 conflict는 알아서 감당하기..

#### 실수로 branch 안 따고 작업했을 때
- git stash : 변경 내용을 따로 담아두고, 이전 commit으로 돌아간다
- git stash list : 담아둔 내용을 확인할 수 있다. 0번이 가장 최신
- git stash pop : 가장 최신 내용을 불러온다.
- git stash apply : 마찬가지로 불러오지만, list 에도 그대로 남아있다.
- git drop [num] : 담아둔 내용을 list에서 삭제한다.

#### 실수로 merge 했을 때 되돌리기
- develope branch에 merge 하려고 한 것을 실수로 master branch에 merge 했다
- 다른 사람이 pull을 하지 않았기 때문에 내 master에 내 commit만 없애면 되는 상황
- 로컬에 있는 master branch는 아직 pull을 하지 않았으므로 병합 전의 상태이다. 이 barnch를 원격 저장소에 덮어 씌운다
- git push -f origin master
- 옵션을 추가해 강제로 A + a -> A 로 변경

## git remote 추가하기
- 여러 원격 저장소를 등록하고 각각에 push 한다
- git remote add [name] [https://~]
- name의 기본값은 origin
- push할 때 git push [name] [branch] 해서 name 만 바꾸면 여러 원격 저장소에 push 가능
- global로 email, password 설정한 경우 email이 동일해야 push 가능
