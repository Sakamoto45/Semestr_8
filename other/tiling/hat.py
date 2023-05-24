import pygame
from math import cos, sin, pi


# pygame setup
pygame.init()
screen = pygame.display.set_mode((1280, 720))
clock = pygame.time.Clock()
running = True
dt = 0

scale = 50

# player_pos = pygame.Vector2(screen.get_width() / 2, screen.get_height() / 2)
origin = pygame.Vector2(screen.get_width() / 2, screen.get_height() / 2)


def hexagon(i, j, direction, cluster_type):
    points = [[origin.x + i + scale*cos(k*2*pi/6), origin.y + j + scale*sin(k*2*pi/6)]
              for k in range(6)]
    pygame.draw.polygon(screen, "red", points, 5)


while running:
    # poll for events
    # pygame.QUIT event means the user clicked X to close your window
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # fill the screen with a color to wipe away anything from last frame
    screen.fill("white")

    # pygame.draw.circle(screen, "red", player_pos, 40)
    hexagon(0, 0, 2, 7)

    # pygame.draw.

    keys = pygame.key.get_pressed()
    if keys[pygame.K_w]:
        origin.y += 300 * dt
    if keys[pygame.K_s]:
        origin.y -= 300 * dt
    if keys[pygame.K_a]:
        origin.x += 300 * dt
    if keys[pygame.K_d]:
        origin.x -= 300 * dt
    if keys[pygame.K_q]:
        scale /= 2 ** dt
    if keys[pygame.K_e]:
        scale *= 2 ** dt

    # flip() the display to put your work on screen
    pygame.display.flip()

    # limits FPS to 60
    # dt is delta time in seconds since last frame, used for framerate-
    # independent physics.
    dt = clock.tick(60) / 1000

pygame.quit()
